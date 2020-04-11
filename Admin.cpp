#include "Admin.h"
#include "ui_Admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_customerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_inventoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
