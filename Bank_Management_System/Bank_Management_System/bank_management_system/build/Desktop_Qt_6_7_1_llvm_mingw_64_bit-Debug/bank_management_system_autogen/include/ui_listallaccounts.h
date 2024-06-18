/********************************************************************************
** Form generated from reading UI file 'listallaccounts.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTALLACCOUNTS_H
#define UI_LISTALLACCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ListAllAccounts
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *ListAllAccounts)
    {
        if (ListAllAccounts->objectName().isEmpty())
            ListAllAccounts->setObjectName("ListAllAccounts");
        ListAllAccounts->resize(418, 298);
        ListAllAccounts->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(ListAllAccounts);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 40, 371, 192));
        pushButton = new QPushButton(ListAllAccounts);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 250, 75, 24));

        retranslateUi(ListAllAccounts);

        QMetaObject::connectSlotsByName(ListAllAccounts);
    } // setupUi

    void retranslateUi(QDialog *ListAllAccounts)
    {
        ListAllAccounts->setWindowTitle(QCoreApplication::translate("ListAllAccounts", "list all accounts", nullptr));
        pushButton->setText(QCoreApplication::translate("ListAllAccounts", "done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListAllAccounts: public Ui_ListAllAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTALLACCOUNTS_H
