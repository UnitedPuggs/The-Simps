#include "Manager.h"
#include "SalesReport.h"
#include "ui_Manager.h"

Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    setupSalesPage();
    setupCustomerPage();
    setupMembershipPage();
    setupInventoryPage();
    setupRebatesPage();
}

Manager::~Manager()
{
    delete ui;
}

void Manager::setupSalesPage()
{

}

void Manager::setupCustomerPage()
{
    ui->customerPage_sortBox->addItem("All");
    ui->customerPage_sortBox->addItem("Regular");
    ui->customerPage_sortBox->addItem("Executive");
}

void Manager::setupInventoryPage()
{
    ui->inventoryPage_sortBox->addItem("Ascending");
    ui->inventoryPage_sortBox->addItem("Descending");
    ui->inventoryPage_sortBox->addItem("Most Sold");
    ui->inventoryPage_sortBox->addItem("Least Sold");
}

void Manager::setupMembershipPage()
{

}

void Manager::setupRebatesPage()
{
    ui->rebatePage_sortBox->addItem("Ascending");
    ui->rebatePage_sortBox->addItem("Descending");
}

void Manager::on_salesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Manager::on_customerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Manager::on_membershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Manager::on_inventoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Manager::on_rebatesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Manager::on_salesPage_previewButton_clicked()
{
    SalesReport *newSales = new SalesReport;
    newSales->show();
}
