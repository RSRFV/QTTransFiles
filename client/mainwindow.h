#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <recvwork.h>
#include <sendwork.h>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QLabel* m_labelPixMap;

    QLabel* m_labelText;

    QStringList m_filePathList;

    bool m_connectSendFlag = false;

    bool m_connectRecvFlag = false;

    sendWork* m_sendWorker;

    recvWork* m_recvWorker;

    QThread* m_sendThread;

    QThread* m_recvThread;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendStart(QStringList filePathList,QString ip ,ushort port);

    void recvStart(QString ip ,ushort port);

    void closeAllConnect();

    void setSendSocketFlag(bool checked);

private slots:
    void on_pushButton_seleectFile_clicked();

    void on_pushButton_sendFile_clicked();

    void on_pushButton_connectSend_clicked();

    void on_pushButton_connectRecv_clicked();

    void on_pushButton_disconnect_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
