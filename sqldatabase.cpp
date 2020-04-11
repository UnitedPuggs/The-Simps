#include "sqldatabase.h"

sqlDatabase::sqlDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QFileInfo db("database.sqlite");
    QString DB_PATH = db.absoluteFilePath();
    qDebug() << DB_PATH;
    database.setDatabaseName(DB_PATH);
    database.open();
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

    query.exec("CREATE TABLE salesTable("
               "PurchaseDate    VARCHAR(15),"
               "CustomerID      INTEGER,"
               "ItemName        VARCHAR(50),"
               "ItemPrice       INTEGER NOT NULL,"
               "Quantity        INTEGER NOT NULL);");
}


