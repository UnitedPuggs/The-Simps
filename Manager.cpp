#include "Manager.h"
#include "ui_Manager.h"

Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->customerPage_sortBox->addItem("All");
    ui->customerPage_sortBox->addItem("Regular");
    ui->customerPage_sortBox->addItem("Executive");
}

Manager::~Manager()
{
    delete ui;
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

