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

<<<<<<< HEAD
=======
struct InventoryList
{
    QString itemName;
    QString itemPrice;
    QString quantityPurchased;
    QString inStock;
    double revenue;

};

>>>>>>> d3787074abe4a62f8a65148155dd9b5df373f541

class sqlDatabase
{
private:
    QSqlDatabase database;
    customerTableInfo customerData;
    salesTableInfo salesData;

public:
    sqlDatabase();
    ~sqlDatabase();

    void createDatabase();
    void readFileCustomer();
    void readFileSales();
    void addCustomerIntoTable(customerTableInfo& customerData);
    void addSalesIntoTable(salesTableInfo& salesData);
<<<<<<< HEAD

    QSqlDatabase GetDatabase() const;
=======
    void handleInventory();
    void checkInventory();
    void updateDB(int,int,double,double);
>>>>>>> d3787074abe4a62f8a65148155dd9b5df373f541

};

#endif // SQLDATABASE_H
