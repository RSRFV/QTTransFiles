#include "sendwork.h"

sendWork::sendWork(QObject *parent) : QObject(parent)
{
}

void sendWork::sendFiles(QStringList filePathList,QString ip ,ushort port)
{
    //打印子线程id
    qDebug()<<"send子线程id"<< QThread::currentThread();
    //通过设置标志位，避免反复创建套接字
    if(m_socketFlag == true)
    {
        //创建套接字
        m_socket = new QTcpSocket;
        //写入描述符
        m_socket->connectToHost(QHostAddress(ip),port);
        //当客户端连接成功时
        connect(m_socket,&QTcpSocket::connected,this,[=]()
        {
            m_connectFlag = true;
            emit connectOK();
        });
        //当客户端断开连接时
        connect(m_socket,&QTcpSocket::disconnected,this,[=]()
        {
            emit disconnectOK();
            m_socket->close();
            m_socket->deleteLater();
        });
        m_socketFlag = false;
    }
    else
    {
        //需要发送的文件数
        int fileNum = filePathList.count();
        //已经发送的文件数
        int num = 0;
        foreach (auto filePath, filePathList) {
            num++;
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
                //发送文件数据
                m_socket->write(fileLine);
                //如果只有一个文件
                if(fileNum==1)
                {
                    //计算总进度
                    percent = (currentPercent*100) / fileSize;
                    //发射sendPercent信号，用于在主线程更新进度条
                    emit sendPercent(percent);
                }
                //qDebug()<<percent<<currentPercent<<fileLine.size();
            }
            //如果只有一堆文件
            if(fileNum>1)
            {
                //计算总进度
                percent = (num*100) / fileNum;
                //发射sendPercent信号，用于在主线程更新进度条
                emit sendPercent(percent);
            }
            //emit showFileName(QString::fromUtf8(fileName));
            //关闭文件
            file.close();
            file.deleteLater();
        }

    }
}

void sendWork::setSocketFlag(bool checked)
{
    m_socketFlag = checked;
}

void sendWork::closeSocket()
{
    if(m_connectFlag == true)
    {
        m_socket->close();
        m_socket->deleteLater();
        m_connectFlag = false;
    }
}
