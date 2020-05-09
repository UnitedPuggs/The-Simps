#include "SalesReport.h"
#include "ui_SalesReport.h"
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <string>

SalesReport::SalesReport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
}

SalesReport::~SalesReport() {
    delete ui;
}

void SalesReport::generateReport() {
    QSqlQuery query;
    query.exec("CREATE TABLE SalesReport("
               "PurchaseDate VARCHAR(15),"
               "CustomerID INTEGER NOT NULL,"
               "ItemName VARCHAR(50),"
               "Quantity INTEGER NOT NULL);");
    QDate endDate, startDate;
    endDate = this->ui->salesPage_endDate->date();
    startDate = this->ui->salesPage_startDate->date();
    int deltaTime = endDate.day() - startDate.day();
    if (deltaTime < 0) {
        QMessageBox::warning(this, "Invalid!", "Please enter a valid start and end date!");
    }
    for (int i = startDate.day(); i <= endDate.day(); ++i) {
        std::string date = "3/" + std::to_string(i) + "/2020";
        QString qDate = QString::fromStdString(date);
        query.prepare("INSERT INTO SalesReport SELECT * FROM SalesTable WHERE PurchaseDate LIKE '%" + qDate + "%';");
        qDebug() << qDate;
        query.exec();
    }
            QMessageBox::information(this, "Success!", "Report has been generated!");
}
