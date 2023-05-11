#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>

class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit myTcpServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr handle) override;

signals:
    void sendDescriptor(qintptr handle);

public slots:

};

#endif // MYTCPSERVER_H
