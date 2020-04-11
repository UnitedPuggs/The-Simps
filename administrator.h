#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "header.h"
#include "sqldatabase.h"
struct uiCustomerInput{
    QString name;
    QString customerID;
    QString executiveType;
    QString expDate;
};
struct uiSalesInput{
    QString purchaseDate;
    QString customerID;
    QString itemName;
    QString itemPrice;
    QString quantity;
};
class administrator
{
public:
    //Instance of the database
    QSqlDatabase database;

    administrator();
    ~administrator();

    void addCustomer();
    void editCustomer();
    void deleteCustomer();

    void addItem();
    void editItem();
    void deleteItem();

    void displayRegularConvertExecutive(); // Convert Regular to Executive Customer
    void displayExecutiveConvertRegular(); // Convert Executive to Regular Customer
};

#endif // ADMINISTRATOR_H
