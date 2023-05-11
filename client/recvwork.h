#ifndef RECVWORK_H
#define RECVWORK_H
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>
#include <QObject>
#include <QFile>

class recvWork : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* m_socket;

    QFile* file;

    bool m_connectFlag = false;

    QString m_clientIp;

    bool m_headFlag = true;

    bool m_dataFlag = true;

    long long m_count = 0;

    long long m_fileSize = 1;

    int m_fileNameSize = 1;

    QString m_fileName = "wy";

    QByteArray fileData;

    qint64 m_bytesAvailed=1;



public:
    explicit recvWork(QObject *parent = nullptr);

    void recvFiles(QString ip ,ushort port);

    void closeSocket();

signals:
    void connectOK();

    void disconnectOK();

    void recvFinished(QString fileName);


public slots:
};

#endif // RECVWORK_H
