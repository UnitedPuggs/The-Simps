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
    query.exec("CREATE TABLE   CustomerTable("
               "Name           VARCHAR(50),"
               "CustomerID     INTEGER NOT NULL PRIMARY KEY,"
               "CustomerType   VARCHAR(4),"
               "ExpirationDate VARCHAR(15),"
               "TotalSpent     DECIMAL(10,2),"
               "TotalRebate    DECIMAL(10,2),"
               "PaidAnnualFee  VARCHAR(4));");

    query.exec("CREATE TABLE  SalesTable("
               "PurchaseDate  VARCHAR(15),"
               "CustomID      INTEGER NOT NULL,"
               "ItemName      VARCHAR(50),"
               "ItemPrice     DECIMAL(10,2),"
               "Quantity      INTEGER NOT NULL);");

    query.exec("CREATE TABLE  InventoryTable("
               "ItemName      VARCHAR(50),"
               "ItemPrice     DECIMAL(10,2),"
               "Quantity      INTEGER NOT NULL,"
               "InStock       INTEGER NOT NULL,"
               "Revenue       Decimal(10,2));");
}

//Reads the warehouse shoppers .txt file (Make sure to change the file path to make it work for you)
void sqlDatabase::readFileCustomer()
{
    QFile file("D:/CS1C/ProjectInfo/warehouse shoppers.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream inFile(&file);

    if(file.isOpen())
    {
        qDebug() << "Opened File";
        while(!inFile.atEnd())
        {
            customerData.name = inFile.readLine();
            customerData.customerID = inFile.readLine();
            customerData.executiveType = inFile.readLine();
            customerData.expDate = inFile.readLine();

            // This function populates customerTable so dont uncomment it unless your table is empty.
            addCustomerIntoTable(customerData);
        }

        file.close();
    }

    else
        qDebug() << "Cannot open file thats used to Read File from Customer list";
}

//Reads the Sales .txt file (Make sure to change the file path to make it work for you)
void sqlDatabase::readFileSales()
{
    QFile file("D:/CS1C/SalesReport/day7.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream inFile(&file);

    if(file.isOpen())
    {
        qDebug() << "Opened File";
        while(!inFile.atEnd())
        {
            salesData.purchaseDate  = inFile.readLine();
            salesData.customerID    = inFile.readLine();
            salesData.itemName      = inFile.readLine();
            salesData.itemPrice     = inFile.readLine();
            salesData.quantity      = inFile.readLine();
            // Don't uncomment unless your table is empty
            addSalesIntoTable(salesData);
        }   file.close();
    }

    else
        qDebug() << "Cannot open file that reads from the Sales list";

}

//Inserts warehouse info into the customerTable
void sqlDatabase::addCustomerIntoTable(customerTableInfo& customerData)
{
    QSqlQuery query;
    query.prepare("CREATE UNIQUE INDEX uidx_customerID"
                  "ON CustomerTable (CustomerID);");

    query.prepare("INSERT OR IGNORE INTO CustomerTable(Name, CustomerID, CustomerType, ExpirationDate)"
                  "VALUES(:name, :ID, :Type, :ExpDate)");

    query.bindValue(":name", customerData.name);
    query.bindValue(":ID", customerData.customerID);
    query.bindValue(":Type", customerData.executiveType);
    query.bindValue(":ExpDate", customerData.expDate);

    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}

//Inserts Sales info into the salesTable
void sqlDatabase::addSalesIntoTable(salesTableInfo& salesData)
{
    QSqlQuery query;

    query.prepare("INSERT INTO SalesTable(PurchaseDate, CustomID, ItemName, ItemPrice, Quantity,Revenue)"
                  "VALUES(:date, :ID, :itemName, :itemPrice, :quantity, :rev)");

    query.bindValue(":date", salesData.purchaseDate);
    query.bindValue(":ID", salesData.customerID);
    query.bindValue(":itemName", salesData.itemName);
    query.bindValue(":itemPrice", salesData.itemPrice);
    query.bindValue(":quantity", salesData.quantity);

    query.bindValue(":rev", );


    fix();

    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}
void sqlDatabase::handleInventory()
{
    QSqlQuery query;

    query.prepare("INSERT INTO InventoryTable(ItemName, ItemPrice, Quantity, InStock)"
                  "VALUES(:name, :price, :quant, :stock)");
    query.bindValue(":name", inventoryData.itemName);
    query.bindValue(":price", inventoryData.itemPrice);
    query.bindValue(":quant", inventoryData.quantityPurchased);
    query.bindValue(":stock", inventoryData.inStock);

    if(!query.exec()){
        qDebug() << "Failed: " << query.lastError();
    }
}
void sqlDatabase::fix(){

    QSqlQuery query;
    query.prepare("SELECT * FROM InventoryTable"
                  " WHERE ItemName       LIKE '%" + salesData.itemName + "%'");

    query.bindValue(":searchingFor", salesData.itemName);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    qDebug() << "Before";

    if (query.next()) {
           qDebug() << "Theres is Copies!!!";

           int quantFromDB = query.value(2).toString().toInt();   //Gets the current Quantity from the DB
           int stockFromDB = query.value(3).toString().toInt();   //Get how much Stock of the item there is left in the DB
           int quantToInput = salesData.quantity.toInt();
           int newStockForDb;
           int newQuantForDb;
           newStockForDb = quantFromDB + quantToInput;
           newQuantForDb =  stockFromDB - quantFromDB;
           double dec = query.value(1).toString().toDouble();

           updateDB(newStockForDb,newQuantForDb,dec);

       }    
    else{
        inventoryData.itemName = salesData.itemName;
        inventoryData.itemPrice = salesData.itemPrice;
        inventoryData.quantityPurchased = salesData.quantity;
        int quant = salesData.quantity.toInt();
        int newStock = 200 - quant;
        QString m;
        inventoryData.inStock = m.number(newStock);
        handleInventory();
        }
}
void sqlDatabase::updateDB(int stock,int quant,double dec){
    QSqlQuery query;
    query.prepare("UPDATE InventoryTable "
                     "SET ItemName = :name, "
                     "    ItemPrice = :price, "
                     "    Quantity = :quant, "
                     "    InStock = :stock "
                     "WHERE ItemName = :c;");

       query.bindValue(":name", salesData.itemName);
       query.bindValue(":price", dec);
       query.bindValue(":quant", stock);
       query.bindValue(":stock", quant);
       query.bindValue(":c",salesData.itemName);

       if(!query.exec())
            qDebug() << query.lastError();

}




