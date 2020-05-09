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
    ui->stackedWidget->setCurrentIndex(1);
}

void Admin::on_membershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin::on_inventoryPage_addButton_clicked()
{

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
