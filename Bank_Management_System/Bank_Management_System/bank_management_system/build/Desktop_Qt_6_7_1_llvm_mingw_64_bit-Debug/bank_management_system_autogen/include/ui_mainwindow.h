/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *createaccountbtn;
    QPushButton *ViewAccountbtn;
    QPushButton *depositbtn;
    QPushButton *withdrawbtn;
    QPushButton *listAllAccountsbtn;
    QPushButton *balanceInquirybtn;
    QPushButton *exitbtn;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(724, 467);
        MainWindow->setAcceptDrops(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images (3).jpeg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 110, 561, 291));
        groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/images/download.jpeg);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 26, 541, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        createaccountbtn = new QPushButton(layoutWidget);
        createaccountbtn->setObjectName("createaccountbtn");

        verticalLayout->addWidget(createaccountbtn);

        ViewAccountbtn = new QPushButton(layoutWidget);
        ViewAccountbtn->setObjectName("ViewAccountbtn");

        verticalLayout->addWidget(ViewAccountbtn);

        depositbtn = new QPushButton(layoutWidget);
        depositbtn->setObjectName("depositbtn");

        verticalLayout->addWidget(depositbtn);

        withdrawbtn = new QPushButton(layoutWidget);
        withdrawbtn->setObjectName("withdrawbtn");

        verticalLayout->addWidget(withdrawbtn);

        listAllAccountsbtn = new QPushButton(layoutWidget);
        listAllAccountsbtn->setObjectName("listAllAccountsbtn");

        verticalLayout->addWidget(listAllAccountsbtn);

        balanceInquirybtn = new QPushButton(layoutWidget);
        balanceInquirybtn->setObjectName("balanceInquirybtn");

        verticalLayout->addWidget(balanceInquirybtn);

        exitbtn = new QPushButton(layoutWidget);
        exitbtn->setObjectName("exitbtn");

        verticalLayout->addWidget(exitbtn);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 0, 421, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:25px;\n"
"background-image: url(:/images/download.jpeg);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        groupBox->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 724, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(exitbtn, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bank management system", nullptr));
        groupBox->setTitle(QString());
        createaccountbtn->setText(QCoreApplication::translate("MainWindow", "CREATE ACCOUNT", nullptr));
        ViewAccountbtn->setText(QCoreApplication::translate("MainWindow", "view account", nullptr));
        depositbtn->setText(QCoreApplication::translate("MainWindow", "deposit", nullptr));
        withdrawbtn->setText(QCoreApplication::translate("MainWindow", "withdraw", nullptr));
        listAllAccountsbtn->setText(QCoreApplication::translate("MainWindow", "list all accounts", nullptr));
        balanceInquirybtn->setText(QCoreApplication::translate("MainWindow", "balance inquiry", nullptr));
        exitbtn->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "       BANK MANAGEMENT SYSTEM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
