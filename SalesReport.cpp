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
    QSqlQuery query1;
    query1.exec("DELETE FROM SalesReport;");
    if (!query1.exec())
        qDebug() << query1.lastError();
//    query1.exec("CREATE TABLE SalesReport("
//               "Date VARCHAR(15),"
//               "CustomerID INTEGER NOT NULL,"
//                "ItemName VARCHAR(50),"
//               "Quantity INTEGER NOT NULL);");
    QDate endDate, startDate;
    endDate = this->ui->salesPage_endDate->date();
    startDate = this->ui->salesPage_startDate->date();
    int deltaTime = endDate.day() - startDate.day();
    if (deltaTime < 0) {
        QMessageBox::warning(this, "Invalid!", "Please enter a valid start and end date!");
    }
    for (int i = startDate.day(); i <= endDate.day(); ++i) {
        QSqlQuery query;
        std::string date = "03/" + std::to_string(i) + "/2020";
        QString qDate = QString::fromStdString(date);
        query.prepare("INSERT INTO SalesReport(Date, CustomerID, ItemName, Quantity) "
                      "SELECT PurchaseDate, CustomID, ItemName, Quantity "
                      "FROM SalesTable WHERE PurchaseDate='" + qDate + "';");
        qDebug() << qDate;
        if (!query.exec())
            qDebug() << query.lastError();
    }
    QMessageBox::information(this, "Success!", "Report has been generated!");
    this->destroy();
}
