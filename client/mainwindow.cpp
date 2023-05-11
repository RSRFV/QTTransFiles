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
    setWindowTitle("client");
    //设置ip地址和端口的默认值
    ui->lineEdit_ip->setText("127.0.0.1");
    ui->lineEdit_recvport->setText("9999");
    ui->lineEdit_sendport->setText("8888");
    //设置进度条的默认值
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    //创建两个label用于在statusbar中显示连接状态
    m_labelPixMap = new QLabel(this);
    m_labelText = new QLabel(this);
    //将label加入到statusbar中
    ui->statusbar->addWidget(m_labelPixMap);
    ui->statusbar->addWidget(m_labelText);

    //实例化一个发送文件的工作类
    sendWork* sendWorker = new sendWork;
    //实例化一个发送线程
    m_sendThread = new QThread;
    //将工作类挪入线程中
    sendWorker->moveToThread(m_sendThread);
    //启动线程
    m_sendThread->start();
    //连接子线程的工作函数
    connect(this,&MainWindow::sendStart,sendWorker,&sendWork::sendFiles);
    //实例化一个接收文件的工作类
    recvWork* recvWorker = new recvWork;
    //实例化一个接收线程
    m_recvThread = new QThread;
    //将工作类挪入线程中
    recvWorker->moveToThread(m_recvThread);
    //启动线程
    m_recvThread->start();
    //连接子线程的工作函数
    connect(this,&MainWindow::recvStart,recvWorker,&recvWork::recvFiles);
    //从子线程中传递进度到主线程，并在进度条上显示
    connect(sendWorker,&sendWork::sendPercent,ui->progressBar,&QProgressBar::setValue);
    //从子线程中获取已经完成接收的文件名并显示
    connect(recvWorker,&recvWork::recvFinished,this,[=](QString fileName)
    {
        ui->plainTextEdit_recv->appendPlainText(fileName+"已接收完毕！！！");
    });
    //若服务器接收端口连接成功时
    connect(sendWorker,&sendWork::connectOK,this,[=]()
    {
        ui->pushButton_disconnect->setEnabled(true);
        ui->pushButton_connectRecv->setDisabled(true);
        ui->plainTextEdit_recv->appendPlainText("服务器接收端口连接成功！！！");
        //m_connectSendFlag和m_connectRecvFlag是两个端口连接成功与否的标志
        m_connectSendFlag =true;
        QPixmap map(":/images/icons/3.bmp");
        if(m_connectRecvFlag ==true)
        {
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器发送和接收端口已连接");
        }
        else {
             m_labelPixMap->setPixmap(map);
             m_labelText->setText("服务器接收端口已连接");
        }
    });
    //若服务器接收端口连接断开时
    connect(sendWorker,&sendWork::disconnectOK,this,[=]()
    {
        ui->pushButton_connectRecv->setEnabled(true);
        ui->plainTextEdit_recv->appendPlainText("服务器接收端口断开连接！！！");
        //m_connectSendFlag和m_connectRecvFlag是两个端口连接成功与否的标志
        m_connectSendFlag =false;
        if(m_connectRecvFlag == false)
        {
            QPixmap map(":/images/icons/4.bmp");
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器连接断开");
            ui->pushButton_disconnect->setDisabled(true);
        }
        else {
            QPixmap map(":/images/icons/3.bmp");
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器发送端口已连接");
        }
    });
    //若服务器发送端口连接成功时
    connect(recvWorker,&recvWork::connectOK,this,[=]()
    {
        ui->pushButton_disconnect->setEnabled(true);
        ui->pushButton_connectSend->setDisabled(true);
        ui->plainTextEdit_recv->appendPlainText("服务器发送端口连接成功！！！");
        m_connectRecvFlag =true;
        QPixmap map(":/images/icons/3.bmp");
        if(m_connectSendFlag ==true)
        {
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器发送和接收端口已连接");
        }
        else {
             m_labelPixMap->setPixmap(map);
             m_labelText->setText("服务器发送端口已连接");
        }
    });
    //若服务器发送端口连接断开时
    connect(recvWorker,&recvWork::disconnectOK,this,[=]()
    {
        ui->pushButton_connectSend->setEnabled(true);
        ui->plainTextEdit_recv->appendPlainText("服务器发送端口断开连接！！！");
        m_connectRecvFlag =false;
        if(m_connectSendFlag == false)
        {
            QPixmap map(":/images/icons/4.bmp");
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器连接断开");
            ui->pushButton_disconnect->setDisabled(true);
        }
        else {
            QPixmap map(":/images/icons/3.bmp");
            m_labelPixMap->setPixmap(map);
            m_labelText->setText("服务器接收端口已连接");
        }
    });

    //通过利用信号槽设置标志位，确定是否在发送文件子线程中创建套接字
    connect(this,&MainWindow::setSendSocketFlag,sendWorker,&sendWork::setSocketFlag);
    //关闭套接字
    connect(this,&MainWindow::closeAllConnect,sendWorker,&sendWork::closeSocket);
    connect(this,&MainWindow::closeAllConnect,recvWorker,&recvWork::closeSocket);
}

MainWindow::~MainWindow()
{
    emit closeAllConnect();
    m_sendThread->quit();
    m_sendThread->wait();
    m_sendThread->deleteLater();
    //m_sendWorker->deleteLater();
    m_recvThread->quit();
    m_recvThread->wait();
    m_recvThread->deleteLater();
    //m_recvWorker->deleteLater();
    delete ui;
}


void MainWindow::on_pushButton_seleectFile_clicked()
{
    ui->plainTextEdit_send->clear();
    //获取用户选择的文件路径，设定不使用本地的对话窗口（win11窗口容易卡死）
    m_filePathList = QFileDialog::getOpenFileNames(this,"请选择一个或多个文件","E:\\learning-materials\\Deep-learning\\yolov5\\yolov5-6\\YOLOv5-Tools-main\\row-data","",nullptr,QFileDialog::DontUseNativeDialog);
    //将选择的路径显示
    foreach (auto i, m_filePathList) {
        ui->plainTextEdit_send->appendPlainText(i);
    }
}

void MainWindow::on_pushButton_sendFile_clicked()
{
    //如果服务器发送端口连接成功
    if(m_connectSendFlag == true)
    {
         //当用户未选择文件时
        if(m_filePathList.count() == 0)
        {
            QMessageBox::warning(this,"warning","请选择文件后再尝试发送");
        }
        else
        {
            //发射工作信号
            emit sendStart(m_filePathList,"",0);
        }
    }
    else
    {
        QMessageBox::warning(this,"warning","未连接到服务器接收端口，请稍后尝试");
    }

}

void MainWindow::on_pushButton_connectSend_clicked()
{
    QString ip =  ui->lineEdit_ip->text();
    QString port = ui->lineEdit_recvport->text();
    //当用户未输入ip地址或端口值时触发警告
    if(ip.count() ==0 || port.count() ==0)
    {
        QMessageBox::warning(this,"warning","请输入ip地址或端口后再尝试连接服务器");
    }
    else
    {
        //发射连接信号
        emit recvStart(ip,port.toUShort());
    }
}

void MainWindow::on_pushButton_connectRecv_clicked()
{
    QString ip =  ui->lineEdit_ip->text();
    QString port = ui->lineEdit_sendport->text();
    //当用户未输入ip地址或端口值时触发警告
    if(ip.count() ==0 || port.count() ==0)
    {
        QMessageBox::warning(this,"warning","请输入ip地址或端口后再尝试连接服务器");
    }
    else
    {
        //设置标志位为true以执行创建套接字的过程
        emit setSendSocketFlag(true);
        //发射连接信号
        emit sendStart(m_filePathList,ip,port.toUShort());
    }
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    //发射关闭套接字信号
    emit closeAllConnect();
}
