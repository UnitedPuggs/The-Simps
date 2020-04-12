#ifndef MANAGER_H
#define MANAGER_H

#include "header.h"

namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void on_salesButton_clicked();

    void on_customerButton_clicked();

    void on_inventoryButton_clicked();

    void on_customerButton_2_clicked();

    void on_membershipButton_clicked();

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H
