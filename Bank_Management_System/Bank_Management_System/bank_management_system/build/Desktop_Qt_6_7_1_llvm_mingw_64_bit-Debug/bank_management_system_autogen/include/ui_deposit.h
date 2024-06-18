/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deposit
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *accountno;
    QLabel *label_2;
    QLineEdit *depositAmount;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *Deposit)
    {
        if (Deposit->objectName().isEmpty())
            Deposit->setObjectName("Deposit");
        Deposit->resize(464, 272);
        Deposit->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(Deposit);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 70, 391, 171));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 20, 421, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        accountno = new QLineEdit(formLayoutWidget);
        accountno->setObjectName("accountno");

        formLayout->setWidget(0, QFormLayout::FieldRole, accountno);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        depositAmount = new QLineEdit(formLayoutWidget);
        depositAmount->setObjectName("depositAmount");

        formLayout->setWidget(1, QFormLayout::FieldRole, depositAmount);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 100, 158, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        label_3 = new QLabel(Deposit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 10, 241, 51));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font-size:25px;"));

        retranslateUi(Deposit);
        QObject::connect(pushButton, &QPushButton::clicked, Deposit, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Deposit);
    } // setupUi

    void retranslateUi(QDialog *Deposit)
    {
        Deposit->setWindowTitle(QCoreApplication::translate("Deposit", "deposit amount", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Deposit", "enter account no:", nullptr));
        label_2->setText(QCoreApplication::translate("Deposit", "enter amount to deposit:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Deposit", "save", nullptr));
        pushButton->setText(QCoreApplication::translate("Deposit", "close", nullptr));
        label_3->setText(QCoreApplication::translate("Deposit", "DEPOSIT AMOUNT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deposit: public Ui_Deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
