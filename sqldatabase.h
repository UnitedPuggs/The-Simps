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

    QSqlDatabase GetDatabase() const;

};

#endif // SQLDATABASE_H
