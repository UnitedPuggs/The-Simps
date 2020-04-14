#include "Admin.h"
#include "ui_Admin.h"

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
