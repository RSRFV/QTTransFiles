#ifndef SENDWORK_H
#define SENDWORK_H
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>
#include <QObject>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>

class sendWork : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* m_socket;

    bool m_socketFlag = true;

    bool m_connectFlag = false;

    QStringList m_filePathList;


public:
    explicit sendWork(QObject *parent = nullptr);

    void sendFiles(QStringList filePathList,QString ip ,ushort port);

    void closeSocket();

    void setSocketFlag(bool checked);

signals:
    void connectOK();

    void disconnectOK();

    void sendPercent(int percent);

public slots:
};

#endif // SENDWORK_H
