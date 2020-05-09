#ifndef SALESREPORT_H
#define SALESREPORT_H
#include "Manager.h"

#include <QMainWindow>

namespace Ui {
class SalesReport;
}

class SalesReport : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalesReport(QWidget *parent = nullptr);
    ~SalesReport();
private slots:
    void generateReport();
private:
    Ui::SalesReport *ui;
};

#endif // SALESREPORT_H
