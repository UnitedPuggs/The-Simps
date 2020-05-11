#ifndef SALESREPORT_H
#define SALESREPORT_H

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

private:
    Ui::SalesReport *ui;
};

#endif // SALESREPORT_H
