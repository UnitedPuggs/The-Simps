#include "SalesReport.h"
#include "ui_SalesReport.h"

SalesReport::SalesReport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
}

SalesReport::~SalesReport()
{
    delete ui;
}
