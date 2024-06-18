#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"createaccount.h"
#include"deposit.h"
#include"withdraw.h"
#include"listallaccounts.h"
#include"viewaccount.h"
#include"balanceinquiry.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createaccountbtn_clicked();

    void on_depositbtn_clicked();

    void on_withdrawbtn_clicked();

    void on_listAllAccountsbtn_clicked();

    void on_balanceInquirybtn_clicked();

    void on_ViewAccountbtn_clicked();


private:
    Ui::MainWindow *ui;
    CreateAccount *ptrCreateAccount;
    Deposit *ptrDeposit;
    Withdraw *ptrWithdraw;
    ListAllAccounts *ptrListAllAccounts;
    ViewAccount *ptrViewAccount;
    BalanceInquiry *ptrBalanceInquiry;
};
#endif // MAINWINDOW_H
