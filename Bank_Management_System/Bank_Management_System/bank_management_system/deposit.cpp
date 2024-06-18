#include "deposit.h"
#include "ui_deposit.h"
#include<QMessageBox>
Deposit::Deposit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_pushButton_2_clicked()
{

    QString accountno = ui->accountno->text();
    QString depositAmountStr = ui->depositAmount->text();
    double depositAmount = depositAmountStr.toDouble();
    qDebug() << "account no " << accountno << ", deposit amount " << depositAmount;

    if (depositAmount <= 0) {
        QMessageBox::warning(this, "Invalid Amount", "Please enter a valid deposit amount.");
        return;
    }

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
    query.prepare("SELECT amount FROM accounts WHERE `account no` = :accountno");
    query.bindValue(":accountno", accountno);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Query execution error: " + query.lastError().text());
        database.close();
        return;
    }

    if (query.next()) {
        double currentAmount = query.value(0).toDouble();
        double newAmount = currentAmount + depositAmount;

        QSqlQuery updateQuery(database);
        updateQuery.prepare("UPDATE accounts SET amount = :newAmount WHERE `account no` = :accountno");
        updateQuery.bindValue(":newAmount", newAmount);
        updateQuery.bindValue(":accountno", accountno);

        if (!updateQuery.exec()) {
            qDebug() << "Update execution error:" << updateQuery.lastError().text();
            QMessageBox::warning(this, "Error", "Update execution error: " + updateQuery.lastError().text());
            database.close();
            return;
        }

        QMessageBox::information(this, "Success", "Money deposited successfully.");
    } else {
        QMessageBox::information(this, "No Account Found", "No account found with the given account number.");
    }

    database.close();
}

