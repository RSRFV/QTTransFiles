/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_sendport;
    QPushButton *pushButton_connectSend;
    QLabel *label_4;
    QLineEdit *lineEdit_recvport;
    QPushButton *pushButton_connectRecv;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QPushButton *pushButton_disconnect;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit_recv;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEdit_send;
    QProgressBar *progressBar;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_seleectFile;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_sendFile;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_sendport = new QLineEdit(widget);
        lineEdit_sendport->setObjectName(QString::fromUtf8("lineEdit_sendport"));

        gridLayout->addWidget(lineEdit_sendport, 0, 1, 1, 1);

        pushButton_connectSend = new QPushButton(widget);
        pushButton_connectSend->setObjectName(QString::fromUtf8("pushButton_connectSend"));

        gridLayout->addWidget(pushButton_connectSend, 0, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_recvport = new QLineEdit(widget);
        lineEdit_recvport->setObjectName(QString::fromUtf8("lineEdit_recvport"));

        gridLayout->addWidget(lineEdit_recvport, 1, 1, 1, 1);

        pushButton_connectRecv = new QPushButton(widget);
        pushButton_connectRecv->setObjectName(QString::fromUtf8("pushButton_connectRecv"));

        gridLayout->addWidget(pushButton_connectRecv, 1, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit_ip = new QLineEdit(widget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 2, 1, 1, 1);

        pushButton_disconnect = new QPushButton(widget);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));
        pushButton_disconnect->setEnabled(false);

        gridLayout->addWidget(pushButton_disconnect, 2, 2, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        plainTextEdit_recv = new QPlainTextEdit(groupBox);
        plainTextEdit_recv->setObjectName(QString::fromUtf8("plainTextEdit_recv"));

        gridLayout_3->addWidget(plainTextEdit_recv, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        plainTextEdit_send = new QPlainTextEdit(groupBox_2);
        plainTextEdit_send->setObjectName(QString::fromUtf8("plainTextEdit_send"));

        gridLayout_4->addWidget(plainTextEdit_send, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_2->addWidget(splitter, 1, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 1);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 50));
        widget_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_seleectFile = new QPushButton(widget_3);
        pushButton_seleectFile->setObjectName(QString::fromUtf8("pushButton_seleectFile"));

        horizontalLayout_3->addWidget(pushButton_seleectFile);

        horizontalSpacer_2 = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_sendFile = new QPushButton(widget_3);
        pushButton_sendFile->setObjectName(QString::fromUtf8("pushButton_sendFile"));

        horizontalLayout_3->addWidget(pushButton_sendFile);

        horizontalSpacer_3 = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_2->addWidget(widget_3, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\217\221\351\200\201\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_connectSend->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\346\216\245\346\224\266\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_connectRecv->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ip\345\234\260\345\235\200:", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pushButton_seleectFile->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButton_sendFile->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
