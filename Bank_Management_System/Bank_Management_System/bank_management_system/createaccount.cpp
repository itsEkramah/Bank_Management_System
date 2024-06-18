#include "createaccount.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateAccount)
{
    ui->setupUi(this);

    // Fetch the next account number and set it in the lineedit_accountno
    updateNextAccountNumber();
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::updateNextAccountNumber()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/RAMLAH/bankmanagement.db");

    if (QFile::exists("D:/RAMLAH/bankmanagement.db")) {
        qDebug() << "Database file exists";
    } else {
        qDebug() << "Database file does not exist";
        return;
    }

    if (!database.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT MAX(`account no`) FROM accounts");

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        database.close();
        return;
    }

    int nextAccountNumber = 1; // Default to 1 if there are no accounts
    if (query.next()) {
        nextAccountNumber = query.value(0).toInt() + 1;
    }

    ui->lineedit_accountno->setText(QString::number(nextAccountNumber));

    database.close();
}

void CreateAccount::on_savebtn_clicked()
{
    QString name = ui->name->text();
    QString phoneno = ui->phoneno->text();
    QString cnic = ui->cnic->text();
    QString amount = ui->startingammount->text();
    QString accountno = ui->lineedit_accountno->text();

    qDebug() << "name = " << name << " phone no = " << phoneno << " CNIC = " << cnic << " starting amount = " << amount;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/RAMLAH/bankmanagement.db");

    if (QFile::exists("D:/RAMLAH/bankmanagement.db")) {
        qDebug() << "Database file exists";
    } else {
        qDebug() << "Database file does not exist";
        return;
    }

    if (!database.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO accounts(`account no`, name, `phone no`, cnic, amount) VALUES (:accountno, :name, :phoneno, :cnic, :amount)");
    query.bindValue(":accountno", accountno);
    query.bindValue(":name", name);
    query.bindValue(":phoneno", phoneno);
    query.bindValue(":cnic", cnic);
    query.bindValue(":amount", amount);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
    } else {
        qDebug() << "Query executed successfully.";
        // Update the next account number for future use
        updateNextAccountNumber();
    }

    database.close();
}
