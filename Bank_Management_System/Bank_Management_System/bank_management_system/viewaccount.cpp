#include "viewaccount.h"
#include "ui_viewaccount.h"

ViewAccount::ViewAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAccount)
    , model(nullptr)
{
    ui->setupUi(this);
}

ViewAccount::~ViewAccount()
{
    delete model;
    delete ui;
}

void ViewAccount::on_findaccount_clicked()
{
    QString accountno = ui->accountno->text();
    qDebug() << "account no " << accountno;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/RAMLAH/bankmanagement.db");

    if (QFile::exists("D:/RAMLAH/bankmanagement.db")) {
        qDebug() << "database file exists";
    } else {
        qDebug() << "database file does not exist";
        return;
    }

    if (!database.open()) {
        qDebug() << "error: unable to open database";
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT * FROM accounts WHERE `account no` LIKE :accountno");
    query.bindValue(":accountno", "%" + accountno + "%");

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        database.close();
        return;
    }

    if (model == nullptr) {
        model = new QSqlQueryModel(this);
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Model error:" << model->lastError().text();
    } else {
        ui->tableView->setModel(model);
        ui->tableView->setColumnWidth(0, 200);
        ui->tableView->setColumnWidth(1, 200);
        ui->tableView->setColumnWidth(2, 200);
    }

    database.close();
}
