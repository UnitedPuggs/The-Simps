#include "administrator.h"

administrator::administrator()
{

}
administrator::~administrator()
{

}
//Adds a customer into the customerTable (hard coded the program but we can easily make it read from the UI)
void administrator::addCustomer(){
    QString name = "Andy";
    QString customerID = "123";
    QString executiveType = "God";
    QString expDate = "Never";
    {
        QSqlQuery query;
        query.prepare("INSERT OR IGNORE INTO customerTable(Name, CustomerID, ExecutiveType, ExpirationDate)"
                      "VALUES(:name, :ID, :Type, :ExpDate)");

        query.bindValue(":name",  name);
        query.bindValue(":ID",    customerID);
        query.bindValue(":Type",  executiveType);
        query.bindValue(":ExpDate", expDate);


        if(!query.exec())
            qDebug() << "Failed: " << query.lastError();
    }
}
