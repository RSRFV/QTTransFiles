#include "recvwork.h"

recvWork::recvWork(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<qintptr>("qintptr");//注册一下"qintptr"这种类型，要不然传输不过来
}

void recvWork::recvFiles(qintptr handle)
{
    //打印子线程id
    qDebug()<<"recv子线程id"<< QThread::currentThread();
    //创建套接字
    m_socket = new QTcpSocket;
    //写入描述符
    m_socket->setSocketDescriptor(handle);
    //获取客户端ip地址
    QString clientIp = m_socket->peerAddress().toString();
    clientIp = clientIp.right(clientIp.count() - clientIp.lastIndexOf(":") - 1);
    //获取客户端端口
    QString port = QString::number(m_socket->peerPort());
    //写入一个stringlist
    m_clientData<<clientIp<<port;
    //将m_clientData送到主线程
    emit getClientData(m_clientData);
    //当客户端断开连接时
    connect(m_socket,&QTcpSocket::disconnected,this,[=]()
    {
        qDebug()<<"recv"<<"客户端断开连接";
        m_socket->close();
        m_socket->deleteLater();
        //将m_clientData送到主线程
        emit disconnectOK(m_clientData);
    });

    /*********************真正接收文件的部分*********************/
    //当readyRead时执行该slot
    connect(m_socket,&QTcpSocket::readyRead,this,[=]() {
        //获取缓冲区内还未读的字节个数
        m_bytesAvailed =  m_socket->bytesAvailable();
        //获缓冲区内还未读的字节个数不等于0则继续读
        while (m_bytesAvailed != 0) {
            //每发送一个文件只执行一次，用于传输文件的大小和名字
            if(m_headFlag == true)
            {
                //当可读字节不够全部接收文件大小、文件名大小和文件名时break
                if(m_socket->bytesAvailable() < 13)
                {
                     break;
                }
                //当可读字节只够接收文件大小、文件名大小时
                if(m_dataFlag == true)
                {
                    //获取文件大小
                    m_socket->read((char*)&m_fileSize,8);
                    //获取文件名大小
                    m_socket->read((char*)&m_fileNameSize,4);
                }
                //当可读字节不够接收文件名时
                if(m_fileNameSize > m_socket->bytesAvailable())
                {
                    m_dataFlag = false;
                    break;
                }
                //获取文件名
                m_fileName = QString::fromUtf8(m_socket->read(m_fileNameSize));
                //用获取的文件名新建一个文件
                file = new QFile("test\\"+m_fileName);
                //将新建的文件已只写方式打开
                file->open(QIODevice::WriteOnly);
                //取反flag，确保上述语句只执行一次
                m_headFlag = false;
                m_dataFlag = false;
            }
            if(m_fileSize - m_count > 65536)
            {

                fileData = m_socket->read(65536);
            }
            else {
                //读取文件内容
                fileData = m_socket->read(m_fileSize - m_count);
            }
            //获取缓冲区内还未读的字节个数
            m_bytesAvailed =  m_socket->bytesAvailable();
            //记录当前已经读到的文件大小
            m_count += fileData.size();
            //将文件内容写入新建的文件
            file->write(fileData);
            //当读取的文件大小等于原本文件大小时
            if(m_count == m_fileSize)
            {
                //初始化文件各项参数，准备下一次文件传输
                m_dataFlag = true;
                m_headFlag = true;
                m_count = 0;
                m_fileSize = 5;
                m_fileNameSize = 5;
                file->close();
                file->deleteLater();
                //向主线程发送文件接收完毕的信号
                emit recvFinished(m_fileName);
             }
        }
     });
}

