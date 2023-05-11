#include "mytcpserver.h"

myTcpServer::myTcpServer(QObject *parent) : QTcpServer(parent)
{

}

//创建一个class，并继承qtcpserver，重写其中的incomingConnection函数，每当有新连接时执行下面的函数
void myTcpServer::incomingConnection(qintptr handle)
{
    //给主线程发送一个信号，并传递描述符
    emit sendDescriptor(handle);
}
