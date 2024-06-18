/********************************************************************************
** Form generated from reading UI file 'viewaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWACCOUNT_H
#define UI_VIEWACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewAccount
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *accountno;
    QPushButton *findaccount;

    void setupUi(QDialog *ViewAccount)
    {
        if (ViewAccount->objectName().isEmpty())
            ViewAccount->setObjectName("ViewAccount");
        ViewAccount->resize(387, 180);
        ViewAccount->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(ViewAccount);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 50, 351, 71));
        pushButton = new QPushButton(ViewAccount);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 130, 75, 24));
        layoutWidget = new QWidget(ViewAccount);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 258, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        accountno = new QLineEdit(layoutWidget);
        accountno->setObjectName("accountno");

        horizontalLayout->addWidget(accountno);

        findaccount = new QPushButton(ViewAccount);
        findaccount->setObjectName("findaccount");
        findaccount->setGeometry(QRect(290, 10, 75, 24));

        retranslateUi(ViewAccount);
        QObject::connect(pushButton, &QPushButton::clicked, ViewAccount, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(ViewAccount);
    } // setupUi

    void retranslateUi(QDialog *ViewAccount)
    {
        ViewAccount->setWindowTitle(QCoreApplication::translate("ViewAccount", "view account", nullptr));
        pushButton->setText(QCoreApplication::translate("ViewAccount", "DONE", nullptr));
        label->setText(QCoreApplication::translate("ViewAccount", "ENTER ACCOUNT NO:", nullptr));
        findaccount->setText(QCoreApplication::translate("ViewAccount", "find account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewAccount: public Ui_ViewAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWACCOUNT_H
