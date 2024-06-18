#include "listallaccounts.h"
#include "ui_listallaccounts.h"
#include<QMessageBox>
ListAllAccounts::ListAllAccounts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ListAllAccounts)
    , model(nullptr)
{
    ui->setupUi(this);
}

ListAllAccounts::~ListAllAccounts()
{
    delete model;
    delete ui;
}

void ListAllAccounts::on_pushButton_clicked()
{

    qDebug() << "Fetching all accounts";

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/RAMLAH/bankmanagement.db");

    if (QFile::exists("D:/RAMLAH/bankmanagement.db")) {
        qDebug() << "Database file exists";
    } else {
        qDebug() << "Database file does not exist";
        QMessageBox::warning(this, "Error", "Database file does not exist");
        return;
    }

    if (!database.open()) {
        qDebug() << "Error: unable to open database";
        QMessageBox::warning(this, "Error", "Unable to open database");
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT * FROM accounts");

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Query execution error: " + query.lastError().text());
        database.close();
        return;
    }

    if (model == nullptr) {
        model = new QSqlQueryModel(this);
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Model error:" << model->lastError().text();
        QMessageBox::warning(this, "Error", "Model error: " + model->lastError().text());
    } else {
        ui->tableView->setModel(model);
        ui->tableView->setColumnWidth(0, 200);  // Adjust as needed
        ui->tableView->setColumnWidth(1, 200);  // Adjust as needed
        ui->tableView->setColumnWidth(2, 200);  // Adjust as needed
        // Adjust more column widths if needed
    }

    database.close();
}

