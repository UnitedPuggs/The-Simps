#include "sqldatabase.h"

sqlDatabase::sqlDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QFileInfo db("database.sqlite");
    QString DB_PATH = db.absoluteFilePath();
    qDebug() << DB_PATH;
    database.setDatabaseName(DB_PATH);
    database.open();
    if(database.isOpen()){
        qDebug() << "Database is Opened Correctly";
    }
    else{
        qDebug() << "Error opening the Database";
    }
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
//Reads the warehouse shoppers .txt file (Make sure to change the file path to make it work for you)
void sqlDatabase::readFileCustomer(){
    QFile file("E:/Shoppers.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream inFile(&file);
    if(file.isOpen()){
        qDebug() << "Opened File";
    }
    else{
        qDebug() << "Cannot open file";
    }
    while(!inFile.atEnd())
    {
        customerData.name  = inFile.readLine();
        customerData.customerID  = inFile.readLine();
        customerData.executiveType   = inFile.readLine();
        customerData.expDate    = inFile.readLine();

       // This function populates customerTable so dont uncomment it unless your table is empty.
       // addCustomerIntoDatabase(customerData);

    }   file.close();
}
//Inserts warehouse info into the customerTable
void sqlDatabase::addCustomerIntoDatabase(customerTableInfo& customerData)
{
    QSqlQuery query;
    query.prepare("CREATE UNIQUE INDEX uidx_name"
                  "ON customerTable (Name);");

    query.prepare("INSERT OR IGNORE INTO customerTable(Name, CustomerID, ExecutiveType, ExpirationDate)"
                  "VALUES(:name, :ID, :Type, :ExpDate)");

    query.bindValue(":name",   customerData.name);
    query.bindValue(":ID",    customerData.customerID);
    query.bindValue(":Type",  customerData.executiveType);
    query.bindValue(":ExpDate",   customerData.expDate);


    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}


