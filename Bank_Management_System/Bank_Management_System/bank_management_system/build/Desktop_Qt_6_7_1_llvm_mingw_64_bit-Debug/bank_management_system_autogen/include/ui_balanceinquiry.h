/********************************************************************************
** Form generated from reading UI file 'balanceinquiry.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEINQUIRY_H
#define UI_BALANCEINQUIRY_H

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

class Ui_BalanceInquiry
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *accountno;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *done;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *BalanceInquiry)
    {
        if (BalanceInquiry->objectName().isEmpty())
            BalanceInquiry->setObjectName("BalanceInquiry");
        BalanceInquiry->resize(514, 226);
        BalanceInquiry->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(BalanceInquiry);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 70, 471, 131));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 40, 471, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        accountno = new QLineEdit(formLayoutWidget);
        accountno->setObjectName("accountno");

        formLayout->setWidget(0, QFormLayout::FieldRole, accountno);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(240, 80, 158, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        done = new QPushButton(widget);
        done->setObjectName("done");

        horizontalLayout->addWidget(done);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        label_2 = new QLabel(BalanceInquiry);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 20, 301, 31));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"font-size:25px;"));

        retranslateUi(BalanceInquiry);
        QObject::connect(pushButton, &QPushButton::clicked, BalanceInquiry, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(BalanceInquiry);
    } // setupUi

    void retranslateUi(QDialog *BalanceInquiry)
    {
        BalanceInquiry->setWindowTitle(QCoreApplication::translate("BalanceInquiry", "balance inquiry", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("BalanceInquiry", "enter account no:", nullptr));
        done->setText(QCoreApplication::translate("BalanceInquiry", "done", nullptr));
        pushButton->setText(QCoreApplication::translate("BalanceInquiry", "CLOSE", nullptr));
        label_2->setText(QCoreApplication::translate("BalanceInquiry", "BALANCE INQUIRY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BalanceInquiry: public Ui_BalanceInquiry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEINQUIRY_H
