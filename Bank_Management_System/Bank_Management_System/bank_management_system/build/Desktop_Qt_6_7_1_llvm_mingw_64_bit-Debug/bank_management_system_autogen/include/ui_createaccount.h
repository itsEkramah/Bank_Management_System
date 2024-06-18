/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *cnic;
    QLabel *label_3;
    QLineEdit *phoneno;
    QLabel *label_4;
    QLineEdit *startingammount;
    QLabel *label_5;
    QComboBox *type;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineedit_accountno;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *savebtn;
    QPushButton *pushButton;
    QLabel *label_8;

    void setupUi(QDialog *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName("CreateAccount");
        CreateAccount->resize(599, 433);
        CreateAccount->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(CreateAccount);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 89, 541, 311));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 70, 491, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        name = new QLineEdit(formLayoutWidget);
        name->setObjectName("name");

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cnic = new QLineEdit(formLayoutWidget);
        cnic->setObjectName("cnic");

        formLayout->setWidget(1, QFormLayout::FieldRole, cnic);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        phoneno = new QLineEdit(formLayoutWidget);
        phoneno->setObjectName("phoneno");

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneno);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        startingammount = new QLineEdit(formLayoutWidget);
        startingammount->setObjectName("startingammount");

        formLayout->setWidget(3, QFormLayout::FieldRole, startingammount);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        type = new QComboBox(formLayoutWidget);
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");

        formLayout->setWidget(4, QFormLayout::FieldRole, type);

        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 201, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        lineedit_accountno = new QLineEdit(layoutWidget);
        lineedit_accountno->setObjectName("lineedit_accountno");

        horizontalLayout->addWidget(lineedit_accountno);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 40, 131, 16));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(340, 240, 181, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        savebtn = new QPushButton(layoutWidget1);
        savebtn->setObjectName("savebtn");

        horizontalLayout_2->addWidget(savebtn);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        label_8 = new QLabel(CreateAccount);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(160, 20, 331, 51));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"font-size:25px;"));

        retranslateUi(CreateAccount);
        QObject::connect(pushButton, &QPushButton::clicked, CreateAccount, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateAccount)
    {
        CreateAccount->setWindowTitle(QCoreApplication::translate("CreateAccount", "Create Account", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("CreateAccount", "name:", nullptr));
        label_2->setText(QCoreApplication::translate("CreateAccount", "CNIC", nullptr));
        label_3->setText(QCoreApplication::translate("CreateAccount", "PHONE NO", nullptr));
        label_4->setText(QCoreApplication::translate("CreateAccount", "Starting amount:", nullptr));
        label_5->setText(QCoreApplication::translate("CreateAccount", "Account type", nullptr));
        type->setItemText(0, QCoreApplication::translate("CreateAccount", "current", nullptr));
        type->setItemText(1, QCoreApplication::translate("CreateAccount", "savings", nullptr));

        label_6->setText(QCoreApplication::translate("CreateAccount", "account no", nullptr));
        lineedit_accountno->setText(QCoreApplication::translate("CreateAccount", "0000", nullptr));
        label_7->setText(QCoreApplication::translate("CreateAccount", "please fill this form:", nullptr));
        savebtn->setText(QCoreApplication::translate("CreateAccount", "save", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateAccount", "close", nullptr));
        label_8->setText(QCoreApplication::translate("CreateAccount", "CREATE ACCOUNT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
