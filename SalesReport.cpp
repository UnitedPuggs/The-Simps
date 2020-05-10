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
    query1.exec("CREATE TABLE SalesReport("
               "Date VARCHAR(15),"
               "CustomerID INTEGER NOT NULL,"
                "ItemName VARCHAR(50),"
               "Quantity INTEGER NOT NULL);");
    QDate endDate, startDate;
    endDate = this->ui->salesPage_endDate->date();
    startDate = this->ui->salesPage_startDate->date();
    int deltaTime = endDate.day() - startDate.day();
    if (deltaTime < 0) {
        QMessageBox::warning(this, "Invalid!", "Please enter a valid start and end date!");
    } else {
        for (int i = startDate.day(); i <= endDate.day(); ++i) {
            QSqlQuery query;
            std::string date = "03/" + std::to_string(i) + "/2020";
            QString qDate = QString::fromStdString(date);
            query.prepare("INSERT INTO SalesReport(Date, CustomerID, ItemName, Quantity) "
                      "SELECT PurchaseDate, CustomID, ItemName, Quantity "
                      "FROM SalesTable WHERE PurchaseDate='" + qDate + "';");
            //qDebug() << qDate;
            if (!query.exec())
                qDebug() << query.lastError();
        if (ui->execButton->isChecked()) {
            int execs[10];
            int index = 0;
            QSqlQuery execQuery("SELECT DISTINCT CustomerTable.CustomerID, CustomerTable.CustomerType "
                                "FROM CustomerTable INNER JOIN SalesReport ON SalesReport.CustomerID = CustomerTable.CustomerID "
                                "WHERE CustomerTable.CustomerType LIKE '%Executive%'");
            while(execQuery.next()) {
               execs[index] = execQuery.value(0).toInt();
               index++;
            }
            query.exec("DELETE FROM SalesReport");
            for (int i = 0; i < 10; ++i) {
                query.prepare("INSERT INTO SalesReport(Date, CustomerID, ItemName, Quantity) "
                              "SELECT PurchaseDate, CustomID, ItemName, Quantity "
                              "FROM SalesTable WHERE CustomID='" + QString::number(execs[i]) + "';");
                //qDebug() << execs[i];
                if (!query.exec())
                    qDebug() << query.lastError();
            }
        }
        if (ui->regularButton->isChecked()) {
            int regs[10];
            int index = 0;
            QSqlQuery execQuery("SELECT DISTINCT CustomerTable.CustomerID, CustomerTable.CustomerType "
                                "FROM CustomerTable INNER JOIN SalesReport ON SalesReport.CustomerID = CustomerTable.CustomerID "
                                "WHERE CustomerTable.CustomerType LIKE '%Regular%'");
            while(execQuery.next()) {
               regs[index] = execQuery.value(0).toInt();
               index++;
            }
            query.exec("DELETE FROM SalesReport");
            for (int i = 0; i < 10; ++i) {
                query.prepare("INSERT INTO SalesReport(Date, CustomerID, ItemName, Quantity) "
                              "SELECT PurchaseDate, CustomID, ItemName, Quantity "
                              "FROM SalesTable WHERE CustomID='" + QString::number(regs[i]) + "';");
                //qDebug() << regs[i];
                if (!query.exec())
                    qDebug() << query.lastError();
            }
        }
     }
        QMessageBox::information(this, "Success!", "Report has been generated!");
        this->hide();
     }
}
