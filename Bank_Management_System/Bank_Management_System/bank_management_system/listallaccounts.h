#ifndef LISTALLACCOUNTS_H
#define LISTALLACCOUNTS_H

#include <QDialog>
#include"databaseheader.h"
namespace Ui {
class ListAllAccounts;
}

class ListAllAccounts : public QDialog
{
    Q_OBJECT

public:
    explicit ListAllAccounts(QWidget *parent = nullptr);
    ~ListAllAccounts();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListAllAccounts *ui;
    QSqlQueryModel *model;
};

#endif // LISTALLACCOUNTS_H
