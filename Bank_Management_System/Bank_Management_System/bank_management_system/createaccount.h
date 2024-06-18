#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include"databaseheader.h"
namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_savebtn_clicked();

private:
    Ui::CreateAccount *ui;
       void updateNextAccountNumber();
};

#endif // CREATEACCOUNT_H
