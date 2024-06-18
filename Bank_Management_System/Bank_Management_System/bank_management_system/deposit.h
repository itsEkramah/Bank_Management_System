#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include"databaseheader.h"
namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
