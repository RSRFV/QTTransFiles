#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //打印主线程id
    qDebug()<<"主线程id"<< QThread::currentThread();
    //设置主窗口标题
    setWindowTitle("server");
    //设置端口的默认值
    ui->lineEdit_recvPort->setText("8888");
    ui->lineEdit_sendPort->setText("9999");

    //实例化myTcpServer对象，用重写incomingConnection的方式获取通讯socket
    m_serverRecv = new myTcpServer(this);
    m_serverSend = new myTcpServer(this);
    //当有新连接时触发该slot，并传递一个与新连接对应的通讯描述符
    connect(m_serverRecv,SIGNAL(sendDescriptor(qintptr)),this,SLOT(newConnectionRecv(qintptr)));
    connect(m_serverSend,SIGNAL(sendDescriptor(qintptr)),this,SLOT(newConnectionSend(qintptr)));
}

MainWindow::~MainWindow()
{
    //清理子线程
    for (int i=0;i<m_recvThreadVector.size();i++) {
        m_recvThreadVector[i]->quit();
        m_recvThreadVector[i]->wait();
        m_recvThreadVector[i]->deleteLater();
    }
    for (int i=0;i<m_sendThreadVector.size();i++) {
        m_sendThreadVector[i]->quit();
        m_sendThreadVector[i]->wait();
        m_sendThreadVector[i]->deleteLater();
    }
    delete ui;
}

//服务器接收端口被连接时
void MainWindow::newConnectionRecv(qintptr handle)
{
    //实例化一个接收文件的工作类
    recvWork* recvWorker = new recvWork;
    //实例化一个接收线程
    QThread* recvThread = new QThread;
    //将接收线程放到vector中
    m_recvThreadVector.push_back(recvThread);
    //将工作类挪入线程中
    recvWorker->moveToThread(recvThread);
    //启动线程
    recvThread->start();
    //获取客户端的ip和端口并显示
    connect(recvWorker,&recvWork::getClientData,this,[=](QStringList clientData)
    {
        QIcon icon(":/images/icons/1.bmp");
        QListWidgetItem* item = new QListWidgetItem(icon,"client("+clientData.at(0)+","+clientData.at(1)+")");
        item->setData(Qt::UserRole,clientData);
        ui->listWidget->addItem(item);
    });
    //获取已经完成接收的文件名并显示
    connect(recvWorker,&recvWork::recvFinished,this,[=](QString fileName)
    {
        ui->plainTextEdit_recv->appendPlainText(fileName+"已接收完毕！！！");
    });
    //连接子线程的工作函数
    connect(this,&MainWindow::recvStart,recvWorker,&recvWork::recvFiles);
    //发射信号激活工作函数并传递通信描述符
    emit recvStart(handle);
    //取消连接，避免多次触发该线程
    disconnect(this,&MainWindow::recvStart,recvWorker,&recvWork::recvFiles);
    //当客户端连接断开时，在主界面上下线该客户端，清理释放内存
    connect(recvWorker,&recvWork::disconnectOK,this,[=](QStringList clientData)
    {
        for (int i = 0;i<ui->listWidget->count();i++) {
            QListWidgetItem* item = ui->listWidget->item(i);
            QStringList itemData = item->data(Qt::UserRole).toStringList();
            if(itemData.at(0) == clientData.at(0) && itemData.at(1) == clientData.at(1))
            {
                delete item;
            }
        }
        //从vector中移除存入的线程
        removeThread(m_recvThreadVector,recvThread);
        recvThread->quit();
        recvThread->wait();
        recvThread->deleteLater();
        recvWorker->deleteLater();
        //qDebug()<<"recv"<<m_sendWorkVector<<m_sendHandleVector<<m_sendThreadVector<<m_recvThreadVector;
    });
}

//服务器发送端口被连接时
void MainWindow::newConnectionSend(qintptr handle)
{

    //实例化一个发送文件的工作类
    sendWork* sendWorker = new sendWork;
    //实例化一个发送线程
    QThread* sendThread = new QThread;
    //将线程放到vector中
    m_sendThreadVector.push_back(sendThread);
    //将工作类放到vector中
    m_sendWorkVector.push_back(sendWorker);
    //将描述符放到vector中
    m_sendHandleVector.push_back(handle);
    //获取客户端的ip和端口并显示
    connect(sendWorker,&sendWork::getClientData,this,[=](QStringList clientData)
    {
//        clientData<<QString::number(m_clientNum);
//        m_clientNum++;
        m_clientIpVector.push_back(clientData.at(0));
        QIcon icon(":/images/icons/1.bmp");
        QListWidgetItem* item = new QListWidgetItem(icon,"client("+clientData.at(0)+","+clientData.at(1)+")");
        item->setData(Qt::UserRole,clientData);
        ui->listWidget->addItem(item);
    });
    //将工作类挪入线程中
    sendWorker->moveToThread(sendThread);
    //启动线程
    sendThread->start();
    //连接子线程的工作函数
    connect(this,&MainWindow::sendStart,sendWorker,&sendWork::sendFiles);
    //发射信号激活工作函数并传递通信描述符
    emit sendStart(handle);
    //取消连接，避免多次触发该线程
    disconnect(this,&MainWindow::sendStart,sendWorker,&sendWork::sendFiles);
    //当客户端连接断开时，在主界面上下线该客户端，清理释放内存
    connect(sendWorker,&sendWork::disconnectOK,this,[=](QStringList clientData)
    {
        m_connectFlag = false;
        for (int i = 0;i<ui->listWidget->count();i++) {
            QListWidgetItem* item = ui->listWidget->item(i);
            QStringList itemData = item->data(Qt::UserRole).toStringList();
            if(itemData.at(0) == clientData.at(0) && itemData.at(1) == clientData.at(1))
            {
                delete item;
            }
        }
        removeIp(m_clientIpVector,clientData.at(0));
        removeThread(m_sendThreadVector,sendThread);
        removeSendWork(m_sendWorkVector,sendWorker);
        removeHandle(m_sendHandleVector,handle);
        sendThread->quit();
        sendThread->wait();
        sendThread->deleteLater();
        sendWorker->deleteLater();
        //qDebug()<<"send"<<m_sendWorkVector<<m_sendHandleVector<<m_sendThreadVector<<m_recvThreadVector;
    });
    m_connectFlag = true;
}

void MainWindow::removeThread(QVector<QThread *> &v, QThread *thread)
{
    for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == thread) {
                    v.erase(it);		// 移除
                    it--;		// 让该迭代器指向前一个
                }
    }
}

void MainWindow::removeSendWork(QVector<sendWork *> &v, sendWork *work)
{
    for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == work) {
                    v.erase(it);		// 移除
                    it--;		// 让该迭代器指向前一个
                }
    }
}

void MainWindow::removeHandle(QVector<qintptr> &v, qintptr handle)
{
    for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == handle) {
                    v.erase(it);		// 移除
                    it--;		// 让该迭代器指向前一个
                }
    }
}

void MainWindow::removeIp(QVector<QString> &v, QString ip)
{
    for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == ip) {
                    v.erase(it);		// 移除
                    it--;		// 让该迭代器指向前一个
                }
    }
}

int MainWindow::getIpIndex(QVector<QString> &v, QString ip)
{
    int num = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == ip) {		// 条件语句
            return num;
        }
        num++;
    }
    return -1;
}

//当发送按钮被点击时
void MainWindow::on_pushButton_sendFile_clicked()
{
    //如果服务器发送端口已经被连接
    if(m_connectFlag == true)
    {
        //当用户未选择文件时
        if(m_filePathList.count() == 0)
        {
            QMessageBox::warning(this,"warning","请选择文件后再尝试发送");
        }
        else
        {
            //获取用户想要发送的对象
            QListWidgetItem* item = ui->listWidget->currentItem();
            //如果未选择，则报一个warning
            if(item == nullptr)
            {
                QMessageBox::warning(this,"warning","请选择一个合适的用户后，再尝试发送");
            }
            else {
                //获取该对象的ip地址
                QString clientIp = item->data(Qt::UserRole).toStringList().at(0);
                //获取该对象ip地址在vector中的索引
                int index = getIpIndex(m_clientIpVector,clientIp);
                //利用该索引获取对应同样位置的工作类
                sendWork* sendWorker = m_sendWorkVector[index];
                //写入要发送的文件路径
                sendWorker->setFilePath(m_filePathList);
                //连接子线程的工作函数
                connect(this,&MainWindow::sendStart,sendWorker,&sendWork::sendFiles);
                //发射信号激活工作函数并传递通信描述符
                emit sendStart(m_sendHandleVector[index]);
                //取消连接，避免多次触发该线程
                disconnect(this,&MainWindow::sendStart,sendWorker,&sendWork::sendFiles);
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"warning","服务器发送端口未被连接，请稍后尝试");
    }



}

void MainWindow::on_pushButton_selectFile_clicked()
{
    //清空
    m_filePathList.clear();
    ui->plainTextEdit_send->clear();
    //获取用户选择的文件路径，设定不使用本地的对话窗口（win11窗口容易卡死）
    m_filePathList = QFileDialog::getOpenFileNames(this,"请选择一个或多个文件","E:\\learning-materials\\Deep-learning\\yolov5\\yolov5-6\\YOLOv5-Tools-main\\row-data","",NULL,QFileDialog::DontUseNativeDialog);
    //将选择的文件路径显示
    foreach (auto i, m_filePathList) {
        ui->plainTextEdit_send->appendPlainText(i);
    }
}

void MainWindow::on_pushButton_listenSend_clicked()
{
    //当用户未输入端口值时触发警告
    if(ui->lineEdit_sendPort->text().count() == 0)
    {
        QMessageBox::warning(this,"warning","请输入端口后再尝试连接服务器");
    }
    else {
        //获取端口值
        ushort port = ui->lineEdit_sendPort->text().toUShort();
        //设置监听ip和端口
        m_serverSend->listen(QHostAddress::AnyIPv4,port);
        //使监听按钮失效
        ui->pushButton_listenSend->setDisabled(true);
    }

}

void MainWindow::on_pushButton_listenRecv_clicked()
{
    //获取端口值
    ushort port = ui->lineEdit_recvPort->text().toUShort();
    //设置监听ip和端口
    m_serverRecv->listen(QHostAddress::AnyIPv4,port);
    //使监听按钮失效
    ui->pushButton_listenRecv->setDisabled(true);
}
