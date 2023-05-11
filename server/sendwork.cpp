#include "sendwork.h"

sendWork::sendWork(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<qintptr>("qintptr");//注册一下"qintptr"这种类型，要不然传输不过来
}


void sendWork::sendFiles(qintptr handle)
{
    //打印子线程id
    qDebug()<<"send子线程id"<< QThread::currentThread()<<handle;
    //使创建套接字的部分只执行一次
    if(m_socketFlag == true)
    {
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
            qDebug()<<"send"<<"客户端断开连接";
            m_socket->close();
            m_socket->deleteLater();
            emit disconnectOK(m_clientData);
        });
        m_socketFlag = false;
    }
    else
    {
    /*********************真正发送文件的部分*********************/
        foreach (auto filePath, m_filePathList) {
            //实例化一个文件类
            QFile file(filePath);
            //以只读方式打开文件
            file.open(QIODevice::ReadOnly);
            //实例化一个文件信息类
            QFileInfo fileInfo(file);
            //获取文件名
            QByteArray fileName = fileInfo.fileName().toUtf8();
            //获取文件大小
            long long fileSize = fileInfo.size();
            //获取文件名大小
            int fileNameSize = fileName.count();
            //定义一个int，用于存储总进度百分比
            int percent;
            //用于存储当前进度
            long long currentPercent = 0;
            //用于存储文件数据
            QByteArray fileLine;
            //发送文件大小
            m_socket->write((char*)&fileSize,8);
            //发送文件名大小
            m_socket->write((char*)&fileNameSize,4);
            //发送文件名字
            m_socket->write(fileName,fileNameSize);
            //文件未读取完时执行
            while (!file.atEnd()) {
                //读取文件内容
                fileLine = file.read(65535);
                //累加每次读取的文件大小
                currentPercent += fileLine.size();
                //计算总进度
                percent = (currentPercent*100) / fileSize;
                //发送文件数据
                m_socket->write(fileLine);
                qDebug()<<percent<<currentPercent<<fileLine.size();
                //发射sendPercent信号，用于在主线程更新进度条
                //emit sendPercent(percent);
            }
            //emit showFileName(QString::fromUtf8(fileName));
            //关闭文件
            file.close();
            file.deleteLater();
            qDebug()<<"**********************************************************";
        }
    }
}



void sendWork::setFilePath(QStringList filePathList)
{
    m_filePathList = filePathList;
}


