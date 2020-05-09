#ifndef MANAGER_H
#define MANAGER_H

#include "header.h"

namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void setupSalesPage();
    void setupCustomerPage();
    void setupInventoryPage();
    void setupMembershipPage();
    void setupRebatesPage();

    void on_salesButton_clicked();
    void on_customerButton_clicked();
    void on_inventoryButton_clicked();
    void on_membershipButton_clicked();
    void on_rebatesButton_clicked();

    void on_salesPage_previewButton_clicked();

    void on_customerPage_sortBox_activated(int index);

    void on_rebatePage_sortBox_activated(int index);

    void on_customerPage_searchButton_clicked();

    void on_membershipPage_searchButton_clicked();
    void on_inventoryPage_searchButton_clicked();

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H
