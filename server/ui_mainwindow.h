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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
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
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_sendPort;
    QPushButton *pushButton_listenSend;
    QLabel *label_4;
    QLineEdit *lineEdit_recvPort;
    QPushButton *pushButton_listenRecv;
    QSplitter *splitter_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_7;
    QListWidget *listWidget;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit_recv;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEdit_send;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_selectFile;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_sendFile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 649);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_sendPort = new QLineEdit(widget);
        lineEdit_sendPort->setObjectName(QString::fromUtf8("lineEdit_sendPort"));
        lineEdit_sendPort->setFont(font1);

        gridLayout->addWidget(lineEdit_sendPort, 0, 1, 1, 1);

        pushButton_listenSend = new QPushButton(widget);
        pushButton_listenSend->setObjectName(QString::fromUtf8("pushButton_listenSend"));
        pushButton_listenSend->setFont(font1);

        gridLayout->addWidget(pushButton_listenSend, 0, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_recvPort = new QLineEdit(widget);
        lineEdit_recvPort->setObjectName(QString::fromUtf8("lineEdit_recvPort"));
        lineEdit_recvPort->setFont(font1);

        gridLayout->addWidget(lineEdit_recvPort, 1, 1, 1, 1);

        pushButton_listenRecv = new QPushButton(widget);
        pushButton_listenRecv->setObjectName(QString::fromUtf8("pushButton_listenRecv"));
        pushButton_listenRecv->setFont(font1);

        gridLayout->addWidget(pushButton_listenRecv, 1, 2, 1, 1);


        gridLayout_5->addWidget(widget, 0, 0, 1, 1);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        groupBox_5 = new QGroupBox(splitter_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(230, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        groupBox_5->setFont(font2);
        gridLayout_7 = new QGridLayout(groupBox_5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        listWidget = new QListWidget(groupBox_5);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setFont(font2);

        gridLayout_7->addWidget(listWidget, 0, 0, 1, 1);

        splitter_2->addWidget(groupBox_5);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font2);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        plainTextEdit_recv = new QPlainTextEdit(groupBox);
        plainTextEdit_recv->setObjectName(QString::fromUtf8("plainTextEdit_recv"));

        gridLayout_3->addWidget(plainTextEdit_recv, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font2);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        plainTextEdit_send = new QPlainTextEdit(groupBox_2);
        plainTextEdit_send->setObjectName(QString::fromUtf8("plainTextEdit_send"));

        gridLayout_4->addWidget(plainTextEdit_send, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);
        splitter_2->addWidget(splitter);

        gridLayout_5->addWidget(splitter_2, 1, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 50));
        widget_2->setFont(font1);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_selectFile = new QPushButton(widget_2);
        pushButton_selectFile->setObjectName(QString::fromUtf8("pushButton_selectFile"));

        gridLayout_2->addWidget(pushButton_selectFile, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        pushButton_sendFile = new QPushButton(widget_2);
        pushButton_sendFile->setObjectName(QString::fromUtf8("pushButton_sendFile"));

        gridLayout_2->addWidget(pushButton_sendFile, 0, 3, 1, 1);


        gridLayout_5->addWidget(widget_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 824, 23));
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
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_listenSend->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\233\221\345\220\254", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_listenRecv->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\233\221\345\220\254", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\234\250\347\272\277", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pushButton_selectFile->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButton_sendFile->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
