#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include "header.h"

class storeManager
{
private:

public:
    storeManager();
    ~storeManager();

    void displaySalesReport();
    void displayTotalPurchases();
    void displayItemQuantities();
    void displayCustomerRebate();
    void displayMembershipExpiration(QString date);
    void displayItemQuantitySold();
    void displayCustomerTotalPurchases();
};

#endif // STOREMANAGER_H
