# Bank_Management_System

## Introduction
In the modern banking sector, the need for efficient, secure, and user-friendly management systems is paramount. As financial institutions increasingly adopt digital solutions to enhance their operations, the development of robust banking software becomes essential. This report presents a comprehensive overview of a Bank Management System developed using C++ with an integrated Graphical User Interface (GUI) and file handling capabilities. 
This Bank Management System project developed with Qt and SQLite

The Bank Management System program aims to streamline and automate core banking functions, providing an intuitive interface for users to manage accounts, process transactions, handle customer information, and generate reports. By incorporating a GUI, the system enhances user experience and accessibility, making it easier for bank staff and customers to interact with the application. The use of file handling ensures that all data is securely stored and efficiently managed.

## Objectives
The primary objectives of this project are:
- To develop a user-friendly interface that simplifies banking operations for both staff and customers.
- To ensure accurate and secure handling of sensitive customer data through effective file management.
- To enhance the efficiency of banking processes such as account management, transaction processing, and report generation.
- To provide a scalable solution that can be expanded with additional features in the future.

## Scope
The scope of this project includes the implementation of essential banking functionalities, focusing on ease of use, data security, and robust performance. The system supports various types of accounts and transactions, offering flexibility and reliability. Key features of the system include:
- **Account Management:** Creation, listing all accounts, and viewing an account.
- **Transaction Processing:** Handling deposits, withdrawals, and transfers securely.
- **Customer Information Management:** Storing and updating customer details efficiently.

The integration of a GUI built using Visual Studio and Qt libraries ensures that the application is not only functional but also visually appealing and easy to navigate. File handling mechanisms are employed with the database to manage data persistence, ensuring that all records are safely stored and easily retrievable.

This report will delve into the system's architecture, design principles, and implementation details, highlighting the role of the GUI and database file handling in enhancing the system's usability and reliability. Through rigorous testing and quality assurance measures, the system's performance and security are validated, ensuring that it meets the high standards required in the banking industry.

## Working
For managing bank accounts, we have used an SQL database file to manage all data of account holders. The system has six primary functions divided into two modules:

### 1. Managing Accounts:
- **Creating Account**
- **Viewing a Specific Account**
- **Listing All Created Accounts**

### 2. Managing Balance in Accounts:
- **Deposit Money**
- **Withdraw Money**
- **Balance Inquiry**
![Alt text](Screenshots\001.jpg)

## Source Code and Working in Detail
Below are all the source codes with the updated database path:

### 1.a - Creating Account
#### Source Code:
```cpp
#include "createaccount.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_savebtn_clicked()
{
    QString name = ui->name->text();
    QString phoneno = ui->phoneno->text();
    QString cnic = ui->cnic->text();
    QString amount = ui->startingammount->text();
    qDebug() << "name = " << name << " phone no = " << phoneno << " CNIC = " << cnic << " starting amount = " << amount;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if(QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db"))
        qDebug() << "database file exists ";
    else {
        qDebug() << "database file does not exist";
        return;
    }

    if(!database.open()) {
        qDebug() << "error: unable to open database";
        return;
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO accounts(name, `phone no`, cnic, amount) VALUES (:name, :phoneno, :cnic, :amount)");
    query.bindValue(":name", name);
    query.bindValue(":phoneno", phoneno);
    query.bindValue(":cnic", cnic);
    query.bindValue(":amount", amount);

    if(!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
    } else {
        qDebug() << "Query executed successfully.";
    }

    database.close();
}
```
![Alt text](Screenshots\002.jpg)

#### Working:
This button works when the user clicks on it and enters data like their name, CNIC, phone number, and other details. The application writes all data to the defined database file. To make this function work, we have added an SQL database file to save data of all bank accounts.

### 1.b - Deposit Button
#### Source Code:
```cpp
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
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if (QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db")) {
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
```
![Alt text](Screenshots\004.jpg)
#### Working:
This button functions when the user clicks on the deposit button and inputs the account number and deposit amount. The application opens the database file, updates the current balance, and displays a success message using `QMessageBox`.

### 1.c - Withdraw Button
#### Source Code:
```cpp
#include "withdraw.h"
#include "ui_withdraw.h"
#include<QMessageBox>

Withdraw::Withdraw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::on_pushButton_clicked()
{
    QString accountno = ui->accountno->text();
    QString withdrawAmountStr = ui->withdrawAmount->text();
    double withdrawAmount = withdrawAmountStr.toDouble();
    qDebug() << "account no " << accountno << ", withdraw amount " << withdrawAmount;

    if (withdrawAmount <= 0) {
        QMessageBox::warning(this, "Invalid Amount", "Please enter a valid withdrawal amount.");
        return;
    }

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if (QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db")) {
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

        if (withdrawAmount > currentAmount) {
            QMessageBox::warning(this, "Insufficient Funds", "Insufficient funds in the account.");
            database.close();
            return;
        }

        double newAmount = currentAmount - withdrawAmount;

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

        QMessageBox::information(this, "Success", "Money withdrawn successfully.");
    } else {
        QMessageBox::information(this, "No Account Found", "No account found with the given account number.");
    }

    database.close();
}
```
![Alt text](Screenshots\005.jpg)

#### Working:
This button functions when the user clicks on the withdraw button and inputs the account number and withdrawal amount. The application opens the database file, updates the current balance, and displays a success message using `QMessageBox`.

### 1.d - Balance Inquiry Button
#### Source Code:
```cpp
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

void BalanceInquiry::on_pushButton_clicked()
{
    QString accountno = ui->accountno->text();
    qDebug() << "account no " << accountno;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if (QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db")) {
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
        QMessageBox::information(this, "Balance Inquiry", "Current balance: " + QString::number(currentAmount));
    } else {
        QMessageBox::information(this, "No Account Found", "No account found with the given account number.");
    }

    database.close();
}
```
![Alt text](Screenshots\007.jpg)

#### Working:
This button functions when the user clicks on the balance inquiry button and inputs the account number. The application opens the database file, retrieves the current balance, and displays it using `QMessageBox`.

### 1.e - View All Accounts
#### Source Code:
```cpp
#include "viewallaccounts.h"
#include "ui_viewallaccounts.h"
#include<QStandardItemModel>
#include<QMessageBox>

ViewAllAccounts::ViewAllAccounts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAllAccounts)
{
    ui->setupUi(this);
}

ViewAllAccounts::~ViewAllAccounts()
{
    delete ui;
}

void ViewAllAccounts::on_pushButton_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if (QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db")) {
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
    query.prepare("SELECT `account no`, name, `phone no`, cnic, amount FROM accounts");

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Query execution error: " + query.lastError().text());
        database.close();
        return;
    }

    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"Account No", "Name", "Phone No", "CNIC", "Amount"});

    while (query.next()) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(query.value(0).toString()));
        items.append(new QStandardItem(query.value(1).toString()));
        items.append(new QStandardItem(query.value(2).toString()));
        items.append(new QStandardItem(query.value(3).toString()));
        items.append(new QStandardItem(query.value(4).toString()));
        model->appendRow(items);
    }

    ui->tableView->setModel(model);
    database.close();
}
```
![Alt text](Screenshots\006.jpg)
#### Working:
This button functions when the user clicks on the view all accounts button. The application opens the database file, retrieves all accounts, and displays them in a table view using `QStandardItemModel`.

### 1.f - View Specific Account
#### Source Code:
```cpp
#include "viewaccount.h"
#include "ui_viewaccount.h"
#include<QMessageBox>

ViewAccount::ViewAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAccount)
{
    ui->setupUi(this);
}

ViewAccount::~ViewAccount()
{
    delete ui;
}

void ViewAccount::on_pushButton_clicked()
{
    QString accountno = ui->accountno->text();
    qDebug() << "account no " << accountno;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db");

    if (QFile::exists("D:/4th semester/BMS/PROJECT SUBMISSION_FINAL/bankmanagement.db")) {
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
    query.prepare("SELECT name, `phone no`, cnic, amount FROM accounts WHERE `account no` = :accountno");
    query.bindValue(":accountno", accountno);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Query execution error: " + query.lastError().text());
        database.close();
        return;
    }

    if (query.next()) {
        QString name = query.value(0).toString();
        QString phoneno = query.value(1).toString();
        QString cnic = query.value(2).toString();
        QString amount = query.value(3).toString();

        QMessageBox::information(this, "Account Details",
                                 "Name: " + name + "\n"
                                 "Phone No: " + phoneno + "\n"
                                 "CNIC: " + cnic + "\n"
                                 "Amount: " + amount);
    } else {
        QMessageBox::information(this, "No Account Found", "No account found with the given account number.");
    }

    database.close();
}
```
![Alt text](Screenshots\002.jpg)
#### Working:
This button functions when the user clicks on the view specific account button and inputs the account number. The application opens the database file, retrieves the account details, and displays them using `QMessageBox`.

#### Running the Bank Management System Project

You can run the Bank Management System project in two ways:

#### Method 1: Using Qt Creator

1. **Install Qt Creator:**
   - Download and install Qt from the [official Qt website](https://www.qt.io/download).
   - Ensure you include Qt Creator and the necessary Qt libraries during installation.

2. **Open the Project:**
   - Launch Qt Creator.
   - Open the project folder containing your Bank Management System project files.

3. **Build and Run the Project:**
   - Click the "Run" button (green play button) in Qt Creator to compile and execute the project.
   - The project should compile successfully, and the application should start, providing the required output.

#### Method 2: Using Visual Studio Community

1. **Install Visual Studio Community:**
   - Download and install Visual Studio Community from the [official Visual Studio website](https://visualstudio.microsoft.com/).

2. **Add Qt Extensions:**
   - Open Visual Studio Community.
   - Navigate to the "Extensions" menu.
   - Search for "Qt" in the extension marketplace.
   - Download and install all available Qt extensions.

3. **Set Up the Project:**
   - Open your Bank Management System project folder in Visual Studio Community.
   - Ensure the project is configured to use the Qt extensions.

4. **Build and Run the Project:**
   - Build the project using the build tools provided by Visual Studio Community.
   - Run the project to obtain the required output. The setup will enable you to run the code smoothly.


## Conclusion
In conclusion, the Bank Management System developed using C++ with an integrated GUI and file handling capabilities effectively meets the objectives of streamlining banking operations, ensuring data security, and enhancing user experience. The system's architecture and design principles, combined with rigorous testing and quality assurance measures, ensure reliable performance and usability. This project demonstrates the potential for further expansion and scalability, offering a robust solution for modern banking needs.
