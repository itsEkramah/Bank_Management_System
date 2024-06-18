#ifndef VIEWACCOUNT_H
#define VIEWACCOUNT_H

#include <QDialog>
#include"databaseheader.h"

namespace Ui {
class ViewAccount;
}

class ViewAccount : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAccount(QWidget *parent = nullptr);
    ~ViewAccount();

private slots:
    void on_findaccount_clicked();

private:
    Ui::ViewAccount *ui;
    QSqlQueryModel *model;
};

#endif // VIEWACCOUNT_H
