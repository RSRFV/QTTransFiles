#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QHostAddress>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextBlock>
#include <QListWidgetItem>

#include <mytcpserver.h>
#include <recvwork.h>
#include <sendwork.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTcpServer* m_serverRecv;

    QTcpServer* m_serverSend;

    QStringList m_filePathList;

    QVector<QThread*> m_recvThreadVector;

    QVector<QThread*> m_sendThreadVector;

    QVector<sendWork*> m_sendWorkVector;

    QVector<qintptr> m_sendHandleVector;

    QVector<QString> m_clientIpVector;

    bool m_connectFlag = false;//服务器发送端口被连接与否的标志

    //int m_clientNum = 0;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void removeThread(QVector<QThread*> &v, QThread* thread);

    void removeSendWork(QVector<sendWork*> &v, sendWork* work);

    void removeHandle(QVector<qintptr> &v, qintptr handle);

    void removeIp(QVector<QString> &v, QString ip);

    int getIpIndex(QVector<QString> &v, QString ip);

private slots:
    void newConnectionRecv(qintptr handle);

    void newConnectionSend(qintptr handle);

    void on_pushButton_sendFile_clicked();

    void on_pushButton_selectFile_clicked();

    void on_pushButton_listenSend_clicked();

    void on_pushButton_listenRecv_clicked();

signals:
    void recvStart(qintptr handle);

    void sendStart(qintptr handle);

    void sendFileStart();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
