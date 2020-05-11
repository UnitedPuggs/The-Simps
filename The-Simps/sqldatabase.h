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

struct inventoryData
{
    QString itemName;
    QString itemPrice;
    QString quantityPurchased;
    QString inStock;
    double revenue;
    double afterTax;
};


class sqlDatabase
{
private:
    QSqlDatabase database;
    customerTableInfo customerData;
    salesTableInfo salesData;
    inventoryData inventoryData;

public:
    sqlDatabase();
    ~sqlDatabase();

    void createDatabase();
    void readFileCustomer();
    void readFileSales();
    void addCustomerIntoTable(customerTableInfo& customerData);
    void addSalesIntoTable(salesTableInfo& salesData);
    QSqlDatabase GetDatabase() const;
    void handleInventory();
    void checkInventory();
    void updateDB(int,int,double,double,double);

};

#endif // SQLDATABASE_H
