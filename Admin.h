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

    void setupCustomerPage();
    void setupInventoryPage();

    void on_inventoryPage_addButton_clicked();

    void on_customerPage_addButton_clicked();


    void on_customerPage_deleteButton_clicked();

    void on_inventoryPage_deleteButton_clicked();

    void on_customerPage_editButton_clicked();

    void on_inventoryPage_editButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
