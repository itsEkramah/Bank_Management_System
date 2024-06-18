#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>
#include"databaseheader.h"
namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
