#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "header.h"

class administrator
{
public:
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
