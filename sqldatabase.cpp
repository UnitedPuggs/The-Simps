#include "sqldatabase.h"

sqlDatabase::sqlDatabase()
{

}

sqlDatabase::~sqlDatabase()
{

}

void sqlDatabase::createDatabase()
{
    QSqlQuery query;
    query.exec("CREATE TABLE customerTable("
               "Name           VARCHAR(50),"
               "CustomerID     INTEGER,"
               "ExecutiveType  INTEGER NOT NULL,"
               "ExpirationDate VARCHAR(15));");
}


