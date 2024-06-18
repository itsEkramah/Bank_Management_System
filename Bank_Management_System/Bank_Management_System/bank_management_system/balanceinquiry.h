#ifndef BALANCEINQUIRY_H
#define BALANCEINQUIRY_H

#include <QDialog>
#include "databaseheader.h"
namespace Ui {
class BalanceInquiry;
}

class BalanceInquiry : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceInquiry(QWidget *parent = nullptr);
    ~BalanceInquiry();

private slots:
    void on_done_clicked();

private:
    Ui::BalanceInquiry *ui;
};

#endif // BALANCEINQUIRY_H
