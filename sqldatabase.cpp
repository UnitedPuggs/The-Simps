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
<<<<<<< HEAD
=======

    query.exec("CREATE TABLE  InventoryTable("
               "ItemName      VARCHAR(50),"
               "ItemPrice     DECIMAL(10,2),"
               "Quantity      INTEGER NOT NULL,"
               "InStock       INTEGER NOT NULL,"
               "Revenue       Decimal(10,2));");
>>>>>>> d3787074abe4a62f8a65148155dd9b5df373f541
}

//Reads the warehouse shoppers .txt file (Make sure to change the file path to make it work for you)
void sqlDatabase::readFileCustomer()
{
    QFile file(":/Shoppers/warehouse shoppers.txt");
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
<<<<<<< HEAD
    QFile file(":/Days/day1.txt");
=======
    QFile file("D:/CS1C/SalesReport/day7.txt");
>>>>>>> d3787074abe4a62f8a65148155dd9b5df373f541
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

    query.prepare("INSERT OR IGNORE INTO CustomerTable(Name, CustomerID, "
                  "CustomerType, ExpirationDate)"
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

    query.prepare("INSERT INTO SalesTable(PurchaseDate, CustomID, ItemName, ItemPrice, Quantity)"
                  "VALUES(:date, :ID, :itemName, :itemPrice, :quantity)");

    query.bindValue(":date", salesData.purchaseDate);
    query.bindValue(":ID", salesData.customerID);
    query.bindValue(":itemName", salesData.itemName);
    query.bindValue(":itemPrice", salesData.itemPrice);
    query.bindValue(":quantity", salesData.quantity);

<<<<<<< HEAD
    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}

QSqlDatabase sqlDatabase::GetDatabase() const
{
    return database;
=======
    checkInventory();

    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}
void sqlDatabase::handleInventory()
{
    QSqlQuery query;

    query.prepare("INSERT INTO InventoryTable(ItemName, ItemPrice, Quantity, InStock,Revenue)"
                  "VALUES(:name, :price, :quant, :stock,:rev)");
    query.bindValue(":name", inventoryData.itemName);
    query.bindValue(":price", inventoryData.itemPrice);
    query.bindValue(":quant", inventoryData.quantityPurchased);
    query.bindValue(":stock", inventoryData.inStock);
    query.bindValue(":rev", inventoryData.revenue);

    if(!query.exec()){
        qDebug() << "Failed: " << query.lastError();
    }
}
void sqlDatabase::checkInventory(){

    QSqlQuery query;
    query.prepare("SELECT * FROM InventoryTable"
                  " WHERE ItemName       LIKE '%" + salesData.itemName + "%'");

    query.bindValue(":searchingFor", salesData.itemName);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    if (query.next()) {

        double itemPrice = query.value(1).toDouble();
        int quantFromDB = query.value(2).toInt();
        double totalRevenue = query.value(4).toDouble();
        int quantToInput = salesData.quantity.toInt();
        int newQuantForDb =  quantFromDB + quantToInput;
        int newStockForDb = 500 - newQuantForDb;
        totalRevenue = newQuantForDb * itemPrice;
        double dec = query.value(1).toString().toDouble();

       if(newStockForDb <= 0 || newStockForDb < 0){
            updateDB(0,quantFromDB,dec,query.value(4).toDouble());
       }
       else{
           qDebug() << "STILL";
            updateDB(newStockForDb,newQuantForDb,dec,totalRevenue);
           }
       }    
    else{
        inventoryData.itemName = salesData.itemName;
        inventoryData.itemPrice = salesData.itemPrice;
        inventoryData.quantityPurchased = salesData.quantity;
        int newStock = 500 - salesData.quantity.toInt();
        QString m;
        inventoryData.inStock = m.number(newStock);
        double totalRev = salesData.quantity.toInt() * inventoryData.itemPrice.toDouble();
        inventoryData.revenue = totalRev;
        handleInventory();
        }
>>>>>>> d3787074abe4a62f8a65148155dd9b5df373f541
}
void sqlDatabase::updateDB(int stock,int quant,double dec,double totalRevenue){
    QSqlQuery query;
    query.prepare("UPDATE InventoryTable "
                     "SET ItemName = :name, "
                     "    ItemPrice = :price, "
                     "    Quantity = :quant, "
                     "    InStock = :stock, "
                     "    Revenue = :rev "
                     "WHERE ItemName = :c;");

       qDebug() << dec << " " << totalRevenue;
       QString price = price.number(dec,'f',2);
       QString rev = rev.number(totalRevenue,'f',2);
       qDebug() << price << " " << rev;

       query.bindValue(":name", salesData.itemName);
       query.bindValue(":price", price);
       query.bindValue(":quant", quant);
       query.bindValue(":stock", stock);
       query.bindValue(":rev", rev);
       query.bindValue(":c",salesData.itemName);

       if(!query.exec())
            qDebug() << query.lastError();
}


