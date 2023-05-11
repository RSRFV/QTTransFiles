#ifndef RECVWORK_H
#define RECVWORK_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QFile>
#include <QHostAddress>

#include <qdebug.h>

class recvWork : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* m_socket;

    QFile* file;

    QStringList m_clientData;

    bool m_headFlag = true;

    bool m_dataFlag = true;

    long long m_count = 0;

    long long m_fileSize = 1;

    int m_fileNameSize = 1;

    QString m_fileName = "wy";

    QByteArray fileData;

    qint64 m_bytesAvailed=1;//可读字节数

public:
    explicit recvWork(QObject *parent = nullptr);

    void recvFiles(qintptr handle);

signals:
    void connectOK();

    void disconnectOK(QStringList clientData);

    void getClientData(QStringList clientData);

    void recvFinished(QString fileName);

public slots:
};
#endif // RECVWORK_H
