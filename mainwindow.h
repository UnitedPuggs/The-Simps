#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"
#include "Admin.h"
#include "Manager.h"
#include "QMessageBox"

enum setIndex
{
    LOGIN_PAGE = 0,
    ADMIN_PAGE = 1,
    STOREMANAGER_PAGE = 2
};

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_pushButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::mainWindow *ui;
    Admin          *admin;
    Manager        *manager;
};

#endif // MAINWINDOW_H
