#include "Admin.h"
#include "ui_Admin.h"
#include "sqldatabase.h"
#include <QMessageBox>




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

    query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate FROM CustomerTable");
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
    determineUpgradeOrDowngrade();
    ui->stackedWidget->setCurrentIndex(2);
}






void Admin::on_inventoryPage_addButton_clicked()
{
    QSqlQuery query;
    Admin     admin;
    QString   itemName  = ui->ItemNameLineEdit->text();
    QString   price     = ui->ItemPriceLineEdit->text();
    QString   quantity  = ui->QuantityLineEdit->text();
    QString   inStock   = ui->InStockLineEdit->text();
    QString   revenue   = ui->RevenueLineEdit->text();

    //If any fields are empty, send an error window to the user
    if(itemName.isEmpty() || price.isEmpty() || quantity.isEmpty() || inStock.isEmpty() || revenue.isEmpty())
        QMessageBox::information(this, "Warning", "Fill in all information before proceeding!");

    else
    {
        //Prepare the database for query to add values to the table
        query.prepare("INSERT OR REPLACE INTO InventoryTable(ItemName, ItemPrice, Quantity, InStock, Revenue) "
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
       QSqlQuery query;

       QString id      = ui->IDLineEdit->text();
       QString name    = ui->NameLineEdit->text();
       QString tr      = ui->RebateLineEdit->text();
       QString ts      = ui->TotalSpentLineEdit->text();
       QString type    = ui->MemberTypeLineEdit->text();
       QString expDate = ui->ExpirationDateLineEdit->text();

       //If any fields are empty, send an error window to the user
       if(name == "" || id == "" || type == "" || expDate =="")
       {
           QMessageBox::information(this, "Warning", "Please fill in Name, ID, MemberType,"
                                                     " and Expiration date to ADD a customer.");
       }

       //Prepare the database for query to add values to the table
       query.prepare("INSERT OR REPLACE INTO CustomerTable(Name,CustomerID, CustomerType, ExpirationDate, TotalSpent, TotalRebate)"
                     "VALUES(:name, :id, :type, :expDate, :ts, :tr)");

       //bind values
       query.bindValue(":name",    name);
       query.bindValue(":id"  ,    id);
       query.bindValue(":type",    type);
       query.bindValue(":expDate", expDate);
       query.bindValue(":ts", ts);
       query.bindValue(":tr", tr);



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






void Admin::determineUpgradeOrDowngrade()
{
    Admin admin;
    QString   name    = ui->NameLineEdit -> text();
    QString   id      = ui->IDLineEdit -> text();
    QString   type    = ui->MemberTypeLineEdit->text();
    QString   expDate = ui->ExpirationDateLineEdit->text();
    QSqlQuery query, upgrade, downgrade;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT Name, CustomerID, CustomerType, ShouldUpgrade FROM CustomerTable");
    upgrade.prepare("UPDATE CustomerTable SET ShouldUpgrade = \"Yes\" WHERE TotalRebate > 120");
    downgrade.prepare("UPDATE CustomerTable SET ShouldUpgrade = \"No\" WHERE TotalRebate < 120");
    if(!query.exec())
        qDebug() << query.lastError();
    if (!upgrade.exec())
        qDebug() << upgrade.lastError();
    if (!downgrade.exec())
        qDebug() << downgrade.lastError();
    model->setQuery(query);
    ui->MembershipTableView->setModel(model);
    ui->MembershipTableView->setColumnWidth(0, 210);
    ui->MembershipTableView->setColumnWidth(1, 100);
    ui->MembershipTableView->setColumnWidth(2, 100);
    ui->MembershipTableView->setColumnWidth(3, 110);
    ui->MembershipTableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->MembershipTableView->resizeRowToContents(i);


}





void Admin::test_purchase() {
    QSqlQuery query, purchase;
    int id = ui->idLine->text().toInt();
    QString salesDate = ui->dateLine->text();
    QString itemName = ui->nameLine->text();
    double itemPrice = ui->priceLine->text().toDouble();
    int qty = ui->qtyLine->text().toInt();
    bool isValid = false;
    query.prepare("SELECT CustomerID FROM CustomerTable");
    if (!query.exec())
        qDebug() << query.exec();

    while(query.next()) {
        ids.push_back(query.value(0).toInt());
    }
    for (unsigned int i = 0; i < ids.size(); ++i) {
        if (id == ids[i]) {
            isValid = true;
            break;
        }
    }
    if(isValid) {
        purchase.prepare("INSERT INTO SalesTable(PurchaseDate, CustomID, ItemName, ItemPrice, Quantity) "
                      "VALUES(:date, :id, :name, :price, :qty)");
        purchase.bindValue(":date", salesDate);
        purchase.bindValue(":id", id);
        purchase.bindValue(":name", itemName);
        purchase.bindValue(":price", itemPrice);
        purchase.bindValue(":qty", qty);

        if (!purchase.exec())
            qDebug() << purchase.lastError();
        QMessageBox::information(this, "Success!", "Test purchase completed!");
        ui->idLine->setText("");
        ui->dateLine->setText("");
        ui->nameLine->setText("");
        ui->priceLine->setText("");
        ui->qtyLine->setText("");
    } else {
        QMessageBox::warning(this, "Failure!", "Sorry, that customer doesn't exist!");
    }
}





void Admin::on_m_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}





void Admin::on_InventoryTableView_clicked(const QModelIndex &index)
{
    QSqlQuery query;
    QString value = ui->InventoryTableView->model()->data(index).toString();

    query.prepare("SELECT * FROM InventoryTable WHERE ItemName = '" + value + "';");

    if(!query.exec())
        qDebug() << query.lastError();

    else
    {
        while(query.next())
        {
            ui->InStockLineEdit->setText(query.value(3).toString() );
            ui->RevenueLineEdit->setText(query.value(4).toString() );
            ui->ItemNameLineEdit->setText(query.value(0).toString() );
            ui->QuantityLineEdit->setText(query.value(2).toString() );
            ui->ItemPriceLineEdit->setText(query.value(1).toString() );
        }
    }
}





void Admin::on_customerPage_tableView_clicked(const QModelIndex &index)
{
   QSqlQuery query;
   QString value = ui->customerPage_tableView->model()->data(index).toString();

   query.prepare("SELECT * FROM CustomerTable WHERE Name = '" + value + "' OR CustomerID = '" + value + "' OR CustomerType = '" + value + "';");

   if(!query.exec())
       qDebug() << query.lastError();

   else
   {
       while(query.next())
       {
           ui->IDLineEdit->setText(query.value(1).toString() );
           ui->NameLineEdit->setText(query.value(0).toString() );
           ui->RebateLineEdit->setText(query.value(6).toString() );
           ui->MemberTypeLineEdit->setText(query.value(2).toString() );
           ui->TotalSpentLineEdit->setText(query.value(5).toString() );
           ui->ExpirationDateLineEdit->setText(query.value(3).toString() );
       }
   }
}
