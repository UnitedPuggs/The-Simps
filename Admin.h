#ifndef ADMIN_H
#define ADMIN_H

#include "header.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_customerButton_clicked();
    void on_inventoryButton_clicked();
    void on_membershipButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
