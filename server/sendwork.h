#ifndef SENDWORK_H
#define SENDWORK_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>

#include <qdebug.h>

class sendWork : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* m_socket;

    bool m_socketFlag = true;

    QStringList m_filePathList;

    QString m_clientIp = "root";

    qintptr m_handle = -1;

    QStringList m_clientData;

public:
    explicit sendWork(QObject *parent = nullptr);

    void sendFiles(qintptr handle);

    void setFilePath(QStringList filePathList);

signals:
    void sendFinishSignal();

    void disconnectOK(QStringList clientData);

    void getClientData(QStringList clientData);
public slots:
};
#endif // SENDWORK_H
