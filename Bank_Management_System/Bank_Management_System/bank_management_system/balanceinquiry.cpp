#include "balanceinquiry.h"
#include "ui_balanceinquiry.h"
#include<QMessageBox>
BalanceInquiry::BalanceInquiry(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BalanceInquiry)
{
    ui->setupUi(this);
}

BalanceInquiry::~BalanceInquiry()
{
    delete ui;
}

void BalanceInquiry::on_done_clicked()
{
    QString accountno = ui->accountno->text();
    qDebug() << "account no " << accountno;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/RAMLAH/bankmanagement.db");

    if (QFile::exists("D:/RAMLAH/bankmanagement.db")) {
        qDebug() << "database file exists";
    } else {
        qDebug() << "database file does not exist";
        QMessageBox::warning(this, "Error", "Database file does not exist");
        return;
    }

    if (!database.open()) {
        qDebug() << "error: unable to open database";
        QMessageBox::warning(this, "Error", "Unable to open database");
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT amount FROM accounts WHERE `account no` LIKE :accountno");
    query.bindValue(":accountno", "%" + accountno + "%");

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Query execution error: " + query.lastError().text());
        database.close();
        return;
    }

    if (query.next()) {
        double amount = query.value(0).toDouble();
        QMessageBox::information(this, "Account Amount", "Amount: " + QString::number(amount));
    } else {
        QMessageBox::information(this, "No Account Found", "No account found with the given account number.");
    }

    database.close();
}

