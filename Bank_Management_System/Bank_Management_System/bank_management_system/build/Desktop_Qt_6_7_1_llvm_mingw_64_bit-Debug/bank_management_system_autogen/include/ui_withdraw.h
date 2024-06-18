/********************************************************************************
** Form generated from reading UI file 'withdraw.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAW_H
#define UI_WITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Withdraw
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *accountno;
    QLabel *label_2;
    QLineEdit *withdrawAmount;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Withdraw)
    {
        if (Withdraw->objectName().isEmpty())
            Withdraw->setObjectName("Withdraw");
        Withdraw->resize(400, 168);
        Withdraw->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(Withdraw);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 50, 311, 71));
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

        withdrawAmount = new QLineEdit(formLayoutWidget);
        withdrawAmount->setObjectName("withdrawAmount");

        formLayout->setWidget(1, QFormLayout::FieldRole, withdrawAmount);

        pushButton = new QPushButton(Withdraw);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 130, 75, 24));
        pushButton_2 = new QPushButton(Withdraw);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 130, 75, 24));

        retranslateUi(Withdraw);
        QObject::connect(pushButton_2, &QPushButton::clicked, Withdraw, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Withdraw);
    } // setupUi

    void retranslateUi(QDialog *Withdraw)
    {
        Withdraw->setWindowTitle(QCoreApplication::translate("Withdraw", "withdraw", nullptr));
        label->setText(QCoreApplication::translate("Withdraw", "enter account no:", nullptr));
        label_2->setText(QCoreApplication::translate("Withdraw", "enter amount to withdraw", nullptr));
        pushButton->setText(QCoreApplication::translate("Withdraw", "done", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Withdraw", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Withdraw: public Ui_Withdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAW_H
