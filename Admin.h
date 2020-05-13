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

    void on_inventoryPage_editButton_clicked();

    void determineUpgradeOrDowngrade();
    void test_purchase();

    void on_m_clicked();

    void on_InventoryTableView_clicked(const QModelIndex &index);

    void on_customerPage_tableView_clicked(const QModelIndex &index);

    void on_testPurchase_inventoryTableView_clicked(const QModelIndex &index);

    void on_inventoryPage_searchBar_textChanged(const QString &arg1);

    void on_testPurchase_searchBar_textChanged(const QString &arg1);

private:
    Ui::Admin *ui;
    std::vector<int> ids;
};

#endif // ADMIN_H
