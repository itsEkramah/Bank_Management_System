#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrCreateAccount = new CreateAccount();
    ptrDeposit = new Deposit();
    ptrWithdraw = new Withdraw();
    ptrBalanceInquiry = new BalanceInquiry();
    ptrViewAccount = new ViewAccount();
    ptrListAllAccounts = new ListAllAccounts();
}

MainWindow::~MainWindow()
{
    delete ptrBalanceInquiry;
    delete ptrCreateAccount;
    delete ptrDeposit;
    delete ptrListAllAccounts;
    delete ptrViewAccount;
    delete ptrWithdraw;
    delete ui;
}

void MainWindow::on_createaccountbtn_clicked()
{
    ptrCreateAccount->show();
}


void MainWindow::on_depositbtn_clicked()
{
    ptrDeposit->show();
}


void MainWindow::on_withdrawbtn_clicked()
{
    ptrWithdraw->show();
}


void MainWindow::on_listAllAccountsbtn_clicked()
{
    ptrListAllAccounts->show();
}


void MainWindow::on_balanceInquirybtn_clicked()
{
    ptrBalanceInquiry->show();
}


void MainWindow::on_ViewAccountbtn_clicked()
{
    ptrViewAccount->show();
}
