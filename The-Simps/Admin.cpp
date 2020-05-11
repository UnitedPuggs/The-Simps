#include "Admin.h"
#include "ui_Admin.h"
#include "sqldatabase.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setupCustomerPage();
}



Admin::~Admin()
{
    delete ui;
}

void Admin::setupCustomerPage()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM CustomerTable");
    query.exec();

    model->setQuery(query);
    ui->customerPage_tableView->setModel(model);
    ui->customerPage_tableView->setColumnWidth(0, 210);
    ui->customerPage_tableView->setColumnWidth(1, 100);
    ui->customerPage_tableView->setColumnWidth(2, 100);
    ui->customerPage_tableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);
}

void Admin::setupInventoryPage()
{

}

void Admin::on_customerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_inventoryButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM InventoryTable");


    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->InventoryTableView->setModel(model);
    ui->InventoryTableView->setColumnWidth(0, 210);
    ui->InventoryTableView->setColumnWidth(1, 100);
    ui->InventoryTableView->setColumnWidth(2, 100);
    ui->InventoryTableView->setColumnWidth(3, 110);
    ui->InventoryTableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->InventoryTableView->resizeRowToContents(i);

    setupInventoryPage();
    ui->stackedWidget->setCurrentIndex(1);
}

void Admin::on_membershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin::on_inventoryPage_addButton_clicked()
{
    Admin     admin;
    QString   itemName  = ui -> ItemNameLineEdit  -> text();
    QString   price     = ui -> ItemPriceLineEdit -> text();
    QString   quantity  = ui -> QuantityLineEdit  -> text();
    QString   inStock   = ui -> InStockLineEdit   -> text();
    QString   revenue   = ui -> RevenueLineEdit   -> text();
    QSqlQuery query;

    //If any fields are empty, send an error window to the user
    if(itemName == "" || price == "" || quantity == "" || inStock == "" || revenue == "")
    {
        QMessageBox::information(this, "Warning", "Please fill in Item Name and Price to ADD an item.");
    }

    //Prepare the database for query to add values to the table
    query.prepare("INSERT OR IGNORE INTO InventoryTable(ItemName, ItemPrice, Quantity, InStock, Revenue)"
                  "VALUES(:itemName, :price, :quantity, :inStock, :revenue)");

    qDebug() << itemName << endl;
    qDebug() << "void Admin::on_inventoryPage_addButton_clicked()" << endl;

    //bind values
    query.bindValue(":itemName", itemName);
    query.bindValue(":price"  ,  price);
    query.bindValue(":quantity", quantity);
    query.bindValue(":inStock",  inStock);
    query.bindValue(":revenue",  revenue);


    //Error message to console if query fails
    if(!query.exec())
    {
        qDebug() << "Failed: " << query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM InventoryTable");
    query.exec();

    model->setQuery(query);
    ui->InventoryTableView->setModel(model);
    ui->InventoryTableView->setColumnWidth(0, 210);
    ui->InventoryTableView->setColumnWidth(1, 100);
    ui->InventoryTableView->setColumnWidth(2, 100);
    ui->InventoryTableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->InventoryTableView->resizeRowToContents(i);

}

/**************************************************************
 * void Admin::on_customerPage_addButton_clicked()
 * ------------------------------------------------------------
 *
 * This function will read in the data inserted by the user.
 * It will create add these values to a single row in the
 * database table.
 *
 * If the NAME, ID, MEMBERSHIP TYPE, OR EXPERATION DATE are
 * left blank, an error window will appear
 *
 *************************************************************/
void Admin::on_customerPage_addButton_clicked()
{
    Admin     admin;
    QString   name    = ui -> NameLineEdit           -> text();
    QString   id      = ui -> IDLineEdit             -> text();
    QString   type    = ui -> MemberTypeLineEdit     -> text();
    QString   expDate = ui -> ExpirationDateLineEdit -> text();
    QSqlQuery query;

    //If any fields are empty, send an error window to the user
    if(name == "" || id == "" || type == "" || expDate =="")
    {
        QMessageBox::information(this, "Warning", "Please fill in Name, ID, MemberType,"
                                                  " and Expiration date to ADD a customer.");
    }

    //Prepare the database for query to add values to the table
    query.prepare("INSERT OR IGNORE INTO CustomerTable(Name,CustomerID, CustomerType, ExpirationDate)"
                  "VALUES(:name, :id, :type, :expDate)");

    //bind values
    query.bindValue(":name",    name);
    query.bindValue(":id"  ,    id);
    query.bindValue(":type",    type);
    query.bindValue(":expDate", expDate);


    //Error message to console if query fails
    if(!query.exec())
    {
        qDebug() << "Failed: " << query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM CustomerTable");
    query.exec();

    model->setQuery(query);
    ui->customerPage_tableView->setModel(model);
    ui->customerPage_tableView->setColumnWidth(0, 210);
    ui->customerPage_tableView->setColumnWidth(1, 100);
    ui->customerPage_tableView->setColumnWidth(2, 100);
    ui->customerPage_tableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);
}

/**************************************************************
 * void Admin::on_customerPage_addButton_clicked()
 * ------------------------------------------------------------
 *
 * This function will read in the ID number inserted by the
 * user. It will delete all information pertaining to a user
 * with that ID number.
 *
 *************************************************************/
void Admin::on_customerPage_deleteButton_clicked()
{
    QString   id      = ui -> IDLineEdit -> text();
    QSqlQuery query;

    query.prepare("DELETE FROM CustomerTable WHERE customerID = :customerID");

    query.bindValue(":customerID", id);

    if(!query.exec())
    {
        qDebug() << "Failed: " << query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM CustomerTable");
    query.exec();

    model->setQuery(query);
    ui->customerPage_tableView->setModel(model);
    ui->customerPage_tableView->setColumnWidth(0, 210);
    ui->customerPage_tableView->setColumnWidth(1, 100);
    ui->customerPage_tableView->setColumnWidth(2, 100);
    ui->customerPage_tableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);
}

void Admin::on_inventoryPage_deleteButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QString   itemName  = ui -> ItemNameLineEdit  -> text();
    QString   price     = ui -> ItemPriceLineEdit -> text();
    QString   quantity  = ui -> QuantityLineEdit  -> text();
    QString   inStock   = ui -> InStockLineEdit   -> text();
    QString   revenue   = ui -> RevenueLineEdit   -> text();
    QSqlQuery query;

    //If any fields are empty, send an error window to the user
    if(itemName == "")
    {
        QMessageBox::information(this, "Warning", "Please fill in the Item Name to DELETE an item.");
    }

    //Prepare the database for query to add values to the table
    query.prepare("DELETE FROM InventoryTable WHERE ItemName = :itemName");

    //bind values
    query.bindValue(":itemName", itemName);


    //Error message to console if query fails
    if(!query.exec())
    {
        qDebug() << "Failed: " << query.lastError();
    }


    query.prepare("SELECT * FROM InventoryTable");
    query.exec();

    model->setQuery(query);
    ui->InventoryTableView->setModel(model);
    ui->InventoryTableView->setColumnWidth(0, 210);
    ui->InventoryTableView->setColumnWidth(1, 100);
    ui->InventoryTableView->setColumnWidth(2, 100);
    ui->InventoryTableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->InventoryTableView->resizeRowToContents(i);


}

void Admin::on_inventoryPage_editButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString   itemName  = ui -> ItemNameLineEdit  -> text();
    QString   price     = ui -> ItemPriceLineEdit -> text();
    QString   quantity  = ui -> QuantityLineEdit  -> text();
    QString   inStock   = ui -> InStockLineEdit   -> text();
    QString   revenue   = ui -> RevenueLineEdit   -> text();

    QSqlQuery query;

    query.prepare("UPDATE InventoryTable "
                  "SET ItemPrice  = :itemPrice, "
                  "    Quantity   = :quantity, "
                  "    InStock    = :inStock, "
                  "    Revenue    = :revenue "
                  "WHERE ItemName = :itemName;");

    query.bindValue(":itemName",  itemName);
    query.bindValue(":itemPrice", price);
    query.bindValue(":quantity",  quantity);
    query.bindValue(":inStock",   inStock);
    query.bindValue(":revenue",   revenue);

    if(!query.exec())
        qDebug() << "Could not update item info." << query.lastError();


    query.prepare("SELECT * FROM InventoryTable");
    query.exec();

    model->setQuery(query);
    ui->InventoryTableView->setModel(model);
    ui->InventoryTableView->setColumnWidth(0, 210);
    ui->InventoryTableView->setColumnWidth(1, 100);
    ui->InventoryTableView->setColumnWidth(2, 100);
    ui->InventoryTableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->InventoryTableView->resizeRowToContents(i);

}
