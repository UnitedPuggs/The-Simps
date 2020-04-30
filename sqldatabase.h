#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include "header.h"

struct customerTableInfo
{
    QString name;
    QString customerID;
    QString executiveType;
    QString expDate;
};

struct salesTableInfo
{
    QString purchaseDate;
    QString customerID;
    QString itemName;
    QString itemPrice;
    QString quantity;
};

struct InventoryList
{
    QString itemName;
    QString itemPrice;
    QString quantityPurchased;
    QString inStock = "100";
};


class sqlDatabase
{
private:
    QSqlDatabase database;
    customerTableInfo customerData;
    salesTableInfo salesData;
    InventoryList inventoryData;

public:
    sqlDatabase();
    ~sqlDatabase();

    void createDatabase();
    void readFileCustomer();
    void readFileSales();
    void addCustomerIntoTable(customerTableInfo& customerData);
    void addSalesIntoTable(salesTableInfo& salesData);
    void handleInventory();
    void fix();

};

#endif // SQLDATABASE_H
