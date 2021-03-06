#include "Manager.h"
#include "SalesReport.h"
#include "ui_Manager.h"
#include <QTimer>
/*!
 * \brief Constructor for Manager
 * \param parent
 */
Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // setupSalesPage();
    setupCustomerPage();
    // setupMembershipPage();
    setupInventoryPage();
    setupRebatesPage();
}



/*!
 * \brief Destructor for manager.
 */
Manager::~Manager()
{
    delete ui;
}





void Manager::setupSalesPage()
{

}




/*!
 * \brief Initializes the sortbox.
 */
void Manager::setupCustomerPage()
{
    ui->customerPage_sortBox->clear();
    ui->customerPage_sortBox->addItem("All");
    ui->customerPage_sortBox->addItem("Regular");
    ui->customerPage_sortBox->addItem("Executive");
}




/*!
 * \brief Initializes the sortbox.
 */
void Manager::setupInventoryPage()
{
    ui->inventoryPage_sortBox->clear();
    ui->inventoryPage_sortBox->addItem("Ascending");
    ui->inventoryPage_sortBox->addItem("Descending");
    ui->inventoryPage_sortBox->addItem("Most Sold");
    ui->inventoryPage_sortBox->addItem("Least Sold");
}





void Manager::setupMembershipPage()
{

}

/*!
 * \brief Initializes the sortbox.
 */
void Manager::setupRebatesPage()
{
    ui->rebatePage_sortBox->clear();
    ui->rebatePage_sortBox->addItem("Ascending");
    ui->rebatePage_sortBox->addItem("Descending");
}

/*!
 * \brief Changes the index of the stackedwidget
 */
void Manager::on_salesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*!
 * \brief Queries customer info from the database.
 */
void Manager::on_customerButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();

//    query.prepare("SELECT CustomerTable.Name, CustomerTable.CustomerID, CustomerTable.CustomerType, "
//                  "Sum(SalesTable.Quantity) AS QtyBought, Sum(InventoryTable.ItemPrice * SalesTable.Quantity) AS TotalSpent "
//                  "FROM SalesTable, InventoryTable, CustomerTable WHERE SalesTable.ItemName = InventoryTable.ItemName "
//                  "AND SalesTable.CustomID = CustomerTable.CustomerID GROUP BY CustomerTable.CustomerID");

    query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, QtyBought, TotalSpent "
                  "FROM CustomerTable;");

    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->customerPage_tableView->setModel(model);
    ui->customerPage_tableView->setColumnWidth(0, 210);
    ui->customerPage_tableView->setColumnWidth(1, 100);
    ui->customerPage_tableView->setColumnWidth(2, 100);
    ui->customerPage_tableView->setColumnWidth(3, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);

    setupCustomerPage();
    ui->stackedWidget->setCurrentIndex(1);
}

/*!
 * \brief Selects a certain amount of columns from CustomerTable to display.
 */
void Manager::on_membershipButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, AnnualFee FROM CustomerTable");

    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->membershipPage_tableView->setModel(model);
    ui->membershipPage_tableView->setColumnWidth(0, 210);
    ui->membershipPage_tableView->setColumnWidth(1, 100);
    ui->membershipPage_tableView->setColumnWidth(2, 100);
    ui->membershipPage_tableView->setColumnWidth(3, 110);
    ui->membershipPage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->membershipPage_tableView->resizeRowToContents(i);

    setupMembershipPage();
    ui->stackedWidget->setCurrentIndex(2);
}

/*!
 * \brief Selects all column from the inventory to display
 */
void Manager::on_inventoryButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM InventoryTable");


    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->inventoryPage_tableView->setModel(model);
    ui->inventoryPage_tableView->setColumnWidth(0, 210);
    ui->inventoryPage_tableView->setColumnWidth(1, 100);
    ui->inventoryPage_tableView->setColumnWidth(2, 100);
    ui->inventoryPage_tableView->setColumnWidth(3, 110);
    ui->inventoryPage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->inventoryPage_tableView->resizeRowToContents(i);

    setupInventoryPage();
    ui->stackedWidget->setCurrentIndex(3);
}


/*!
 * \brief Generates the rebate per customer at a 2% rate from their totalspent
 */
void Manager::on_rebatesButton_clicked()
{
    QSqlQuery query, rebate;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT Name, CustomerID, CustomerType, TotalRebate FROM CustomerTable WHERE CustomerType = 'Executive'");
    rebate.prepare("UPDATE CustomerTable SET TotalRebate = TotalSpent * 0.02");
    if(!query.exec())
        qDebug() << query.lastError();
    if (!rebate.exec())
        qDebug() << rebate.lastError();
    model->setQuery(query);
    ui->rebatePage_tableView->setModel(model);
    ui->rebatePage_tableView->setColumnWidth(0, 210);
    ui->rebatePage_tableView->setColumnWidth(1, 100);
    ui->rebatePage_tableView->setColumnWidth(2, 100);
    ui->rebatePage_tableView->setColumnWidth(3, 110);
    ui->rebatePage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);

    ui->stackedWidget->setCurrentIndex(4);
}




/*!
 * \brief Creates a SalesReport window whenever the button is activated.
 */
void Manager::on_salesPage_previewButton_clicked()
{
    SalesReport *newSales = new SalesReport;
    newSales->show();
}




/*!
 * \brief Generates a query based on what index the sort box is on.
 * \param index
 */
void Manager::on_customerPage_sortBox_activated(int index)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    // All Selected
    if(index == 0) {
//        query.prepare("SELECT CustomerTable.Name, CustomerTable.CustomerID, CustomerTable.CustomerType, "
//                      "Sum(SalesTable.Quantity) AS QtyBought, Sum(InventoryTable.ItemPrice * SalesTable.Quantity) AS TotalSpent "
//                      "FROM SalesTable, InventoryTable, CustomerTable WHERE SalesTable.ItemName = InventoryTable.ItemName "
//                      "AND SalesTable.CustomID = CustomerTable.CustomerID GROUP BY CustomerTable.CustomerID");

        query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, QtyBought, TotalSpent "
                      "FROM CustomerTable;");
    }

    // Regular
    else if(index == 1) {
//        query.prepare("SELECT CustomerTable.Name, CustomerTable.CustomerID, CustomerTable.CustomerType, "
//                      "Sum(SalesTable.Quantity) AS QtyBought, Sum(InventoryTable.ItemPrice * SalesTable.Quantity) AS TotalSpent "
//                      "FROM SalesTable, InventoryTable, CustomerTable WHERE SalesTable.ItemName = InventoryTable.ItemName "
//                      "AND SalesTable.CustomID = CustomerTable.CustomerID AND CustomerTable.CustomerType = 'Regular' GROUP BY CustomerTable.CustomerID");

        query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, QtyBought, TotalSpent "
                      "FROM CustomerTable WHERE CustomerType = 'Regular';");
    }

    // Executive
    else if(index == 2) {
//        query.prepare("SELECT CustomerTable.Name, CustomerTable.CustomerID, CustomerTable.CustomerType, "
//                      "Sum(SalesTable.Quantity) AS QtyBought, Sum(InventoryTable.ItemPrice * SalesTable.Quantity) AS TotalSpent "
//                      "FROM SalesTable, InventoryTable, CustomerTable WHERE SalesTable.ItemName = InventoryTable.ItemName "
//                      "AND SalesTable.CustomID = CustomerTable.CustomerID AND CustomerTable.CustomerType = 'Executive' GROUP BY CustomerTable.CustomerID");

        query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, QtyBought, TotalSpent "
                      "FROM CustomerTable WHERE CustomerType = 'Executive';");
    }

    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->customerPage_tableView->setModel(model);
    ui->customerPage_tableView->setColumnWidth(0, 210);
    ui->customerPage_tableView->setColumnWidth(1, 100);
    ui->customerPage_tableView->setColumnWidth(2, 100);
    ui->customerPage_tableView->setColumnWidth(3, 110);
    ui->customerPage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->customerPage_tableView->resizeRowToContents(i);
}






/*!
 * \brief Generates a query based on what index the sortbox is on.
 * \param index
 */
void Manager::on_rebatePage_sortBox_activated(int index)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Ascending
    if(index == 0) {
        query.prepare("SELECT Name, CustomerID, CustomerType, TotalSpent"
                      " FROM CustomerTable"
                      " WHERE CustomerType = 'Executive'"
                      " ORDER BY CustomerID ASC");
    }

    // Descending
    else if(index == 1) {
        query.prepare("SELECT Name, CustomerID, CustomerType, TotalSpent"
                      " FROM CustomerTable"
                      " WHERE CustomerType = 'Executive'"
                      " ORDER BY CustomerID DESC");
    }

    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->rebatePage_tableView->setModel(model);
    ui->rebatePage_tableView->setColumnWidth(0, 210);
    ui->rebatePage_tableView->setColumnWidth(1, 100);
    ui->rebatePage_tableView->setColumnWidth(2, 100);
    ui->rebatePage_tableView->setColumnWidth(3, 110);
    ui->rebatePage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->rebatePage_tableView->resizeRowToContents(i);
}




/*!
 * \brief Generates an sql query based on what index the sortbox is on.
 * \param index
 */
void Manager::on_inventoryPage_sortBox_activated(int index)
{

    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Ascending
    if(index == 0) {
        query.prepare("SELECT ItemName, ItemPrice, Quantity, InStock, Revenue"
                      " FROM InventoryTable"
                      " ORDER BY ItemName ASC");
    }

    // Descending
    else if(index == 1) {
        query.prepare("SELECT ItemName, ItemPrice, Quantity, InStock, Revenue"
                      " FROM InventoryTable"
                      " ORDER BY ItemName DESC");
    }
    else if(index == 2) {
        query.prepare("SELECT ItemName, ItemPrice, Quantity, InStock, Revenue"
                      " FROM InventoryTable"
                      " ORDER BY Revenue DESC");
    }
    else if(index == 3) {
        query.prepare("SELECT ItemName, ItemPrice, Quantity, InStock, Revenue"
                      " FROM InventoryTable"
                      " ORDER BY Revenue ASC");
    }

    if(!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->inventoryPage_tableView->setModel(model);
    ui->inventoryPage_tableView->setColumnWidth(0, 210);
    ui->inventoryPage_tableView->setColumnWidth(1, 100);
    ui->inventoryPage_tableView->setColumnWidth(2, 100);
    ui->inventoryPage_tableView->setColumnWidth(3, 110);
    ui->inventoryPage_tableView->setColumnWidth(4, 110);

    for (int i = 0; i < model->rowCount(); ++i)
        ui->inventoryPage_tableView->resizeRowToContents(i);
}






/*!
 * \brief Looks for customers that have the name or ID the user is looking for.
 */
void Manager::on_customerPage_searchButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();
    QString searchingFor = ui->customerPage_searchBar->text();

    query.prepare("SELECT Name, CustomerID, CustomerType, TotalSpent FROM CustomerTable"
                  " WHERE Name       LIKE '%" + searchingFor + "%'"
                  " OR    CustomerID LIKE '%" + searchingFor + "%';");

    query.bindValue(":searchingFor", searchingFor);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    if(ui->customerPage_searchBar->text().isEmpty()) {
        on_customerButton_clicked();
    }

    else {
        model->setQuery(query);
        ui->customerPage_tableView->setModel(model);
        ui->customerPage_tableView->setColumnWidth(0, 210);
        ui->customerPage_tableView->setColumnWidth(1, 100);
        ui->customerPage_tableView->setColumnWidth(2, 100);
        ui->customerPage_tableView->setColumnWidth(3, 110);
        ui->customerPage_tableView->setColumnWidth(4, 110);

        for (int i = 0; i < model->rowCount(); ++i)
            ui->customerPage_tableView->resizeRowToContents(i);
    }
}






/*!
 * \brief Allows for a monthly search on expiration dates of members
 */
void Manager::on_membershipPage_searchButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();
    QString searchingFor = ui->membershipPage_searchBar->text();

    if (searchingFor.toLower() == "january" || searchingFor == "1") {
        searchingFor = "01";
    } else if (searchingFor.toLower() == "february" || searchingFor == "2") {
         searchingFor = "02";
    } else if (searchingFor.toLower() == "march" || searchingFor == "3") {
         searchingFor = "03";
    } else if (searchingFor.toLower() == "april" || searchingFor == "4") {
         searchingFor = "04";
    } else if (searchingFor.toLower() == "may" || searchingFor == "5") {
         searchingFor = "05";
    } else if (searchingFor.toLower() == "june" || searchingFor == "6") {
         searchingFor = "06";
    } else if (searchingFor.toLower() == "july" || searchingFor == "7") {
         searchingFor = "07";
    } else if (searchingFor.toLower() == "august" || searchingFor == "8") {
         searchingFor = "08";
    } else if (searchingFor.toLower() == "september" || searchingFor == "9") {
         searchingFor = "09";
    } else if (searchingFor.toLower() == "october" || searchingFor == "10") {
         searchingFor = "10";
    } else if (searchingFor.toLower() == "november" || searchingFor == "11") {
         searchingFor = "11";
    } else if (searchingFor.toLower() == "december" || searchingFor == "12") {
         searchingFor = "12";
    }
    query.prepare("SELECT Name, CustomerID, CustomerType, ExpirationDate, AnnualFee FROM Customertable WHERE strftime('%m', ExpirationDate) in ('" + searchingFor + "')");
    query.bindValue(":searchingFor", searchingFor);
    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    if(ui->membershipPage_searchBar->text().isEmpty()) {
        on_membershipButton_clicked();
    }

    else {
        model->setQuery(query);
        ui->membershipPage_tableView->setModel(model);
        ui->membershipPage_tableView->setColumnWidth(0, 210);
        ui->membershipPage_tableView->setColumnWidth(1, 100);
        ui->membershipPage_tableView->setColumnWidth(2, 100);
        ui->membershipPage_tableView->setColumnWidth(3, 110);
        ui->membershipPage_tableView->setColumnWidth(4, 110);
        ui->membershipPage_tableView->setColumnWidth(5, 110);

        for (int i = 0; i < model->rowCount(); ++i)
            ui->membershipPage_tableView->resizeRowToContents(i);
    }
}





/*!
 * \brief Looks for items in InventoryTable
 */
void Manager::on_inventoryPage_searchButton_clicked()
{
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();
    QString searchingFor = ui->inventoryPage_searchBar->text();


    query.prepare("SELECT ItemName, ItemPrice, Quantity, InStock FROM InventoryTable"
                  " WHERE ItemName       LIKE '%" + searchingFor + "%'"
                  " OR    ItemPrice LIKE '%" + searchingFor + "%';");

    query.bindValue(":searchingFor", searchingFor);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    if(ui->inventoryPage_searchBar->text().isEmpty()) {
        on_inventoryButton_clicked();
    }

    else {
        model->setQuery(query);
        ui->inventoryPage_tableView->setModel(model);
        ui->inventoryPage_tableView->setColumnWidth(0, 210);
        ui->inventoryPage_tableView->setColumnWidth(1, 100);
        ui->inventoryPage_tableView->setColumnWidth(2, 100);
        ui->inventoryPage_tableView->setColumnWidth(3, 110);
        ui->inventoryPage_tableView->setColumnWidth(4, 110);


        for (int i = 0; i < model->rowCount(); ++i)
            ui->inventoryPage_tableView->resizeRowToContents(i);
    }
}




/*!
 * \brief Calls the inventory search function when text is changed.
 */
void Manager::refreshSearch() {
    on_inventoryPage_searchButton_clicked();
}





/*!
 * \brief Parses the information from SalesReport to be displayed in the TableView.
 */
void Manager::generateReport() {
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.prepare("SELECT * FROM SalesReport");
    if (!query.exec())
        qDebug() << query.lastError();

    model->setQuery(query);
    ui->salesPage_tableView->setModel(model);
    ui->salesPage_tableView->setColumnWidth(0, 205);
    ui->salesPage_tableView->setColumnWidth(1, 205);
    ui->salesPage_tableView->setColumnWidth(3, 205);
    ui->salesPage_tableView->setColumnWidth(4, 205);

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->salesPage_tableView->resizeRowToContents(i);
    }
    QSqlQuery query1("SELECT DISTINCT CustomerTable.CustomerID, CustomerTable.CustomerType "
                     "FROM CustomerTable INNER JOIN SalesReport "
                     "ON SalesReport.CustomerID = CustomerTable.CustomerID");

    int execCount = 0, normalCount = 0;

    while (query1.next()) {
        QString customerType = query1.value(1).toString();
        if (customerType == "Executive")
            execCount++;
        else
            normalCount++;
    }
    QSqlQuery total("SELECT Sum(InventoryTable.ItemPrice * SalesReport.Quantity) AS GRANDTOTAL FROM InventoryTable, SalesReport "
                "WHERE InventoryTable.ItemName = SalesReport.ItemName");
    double grandTotal = 0;
    while (total.next()) {
    grandTotal = total.value(0).toDouble();
    }
    ui->grandTotalLin->setText(QString::number(grandTotal));
    ui->normalLine->setText(QString::number(normalCount));
    ui->executiveLine->setText(QString::number(execCount));
}




/*!
 * \brief Calls the member search function when text is changed.
 */
void Manager::refreshMonthsSearch() {
    on_membershipPage_searchButton_clicked();
}




/*!
 * \brief Calls the customer search function when text is changed.
 */
void Manager::refreshCustomerSearch() {
    on_customerPage_searchButton_clicked();
}





/*!
 * \brief Looks for customers with the user inputted ID and calculates totals and all that.
 */
void Manager::sales_search() {
    QSqlQuery query;
    QSqlRecord record;
    QSqlQueryModel *model = new QSqlQueryModel();
    QString searchingFor = ui->sales_searchBar->text();

    query.prepare("SELECT SalesReport.Date, SalesReport.CustomerID, SalesReport.ItemName, SalesReport.Quantity, InventoryTable.ItemPrice * SalesReport.Quantity "
                  "AS SPENT FROM InventoryTable, SalesReport WHERE InventoryTable.ItemName = SalesReport.ItemName "
                  "AND SalesReport.CustomerID LIKE '%"+ searchingFor +"%';");

    query.bindValue(":searchingFor", searchingFor);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    if(ui->sales_searchBar->text().isEmpty()) {
        generateReport();
    }

    else {
        model->setQuery(query);
        ui->salesPage_tableView->setModel(model);
        ui->salesPage_tableView->setColumnWidth(0, 150);
        ui->salesPage_tableView->setColumnWidth(1, 150);
        ui->salesPage_tableView->setColumnWidth(3, 150);
        ui->salesPage_tableView->setColumnWidth(4, 150);
        ui->salesPage_tableView->setColumnWidth(5, 150);

        QSqlQuery total("SELECT Sum(InventoryTable.ItemPrice * SalesReport.Quantity) AS GRANDTOTAL FROM InventoryTable, SalesReport "
                    "WHERE InventoryTable.ItemName = SalesReport.ItemName AND SalesReport.CustomerID LIKE '%" + searchingFor + "%'");
        double grandTotal = 0;
        while (total.next()) {
        grandTotal = total.value(0).toDouble();
        }
        ui->grandTotalLin->setText(QString::number(grandTotal));

        for (int i = 0; i < model->rowCount(); ++i)
            ui->salesPage_tableView->resizeRowToContents(i);


        QSqlQuery query1("SELECT DISTINCT CustomerTable.CustomerID, CustomerTable.CustomerType "
                         "FROM CustomerTable INNER JOIN SalesReport "
                         "ON SalesReport.CustomerID = CustomerTable.CustomerID "
                         "WHERE SalesReport.CustomerID LIKE '%" + searchingFor + "%'");

        int execCount = 0, normalCount = 0;

        while (query1.next()) {
            QString customerType = query1.value(1).toString();
            if (customerType == "Executive")
                execCount++;
            else
                normalCount++;
        }
        ui->normalLine->setText(QString::number(normalCount));
        ui->executiveLine->setText(QString::number(execCount));
    }
}




/*!
 * \brief Calls function when text is changed.
 */
void Manager::refreshSalesSearch() {
    sales_search();
}

