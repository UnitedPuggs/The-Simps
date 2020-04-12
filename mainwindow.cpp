#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_clicked()
{
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->PasswordLineEdit->text();

    if(username == "admin" && password == "admin")
    {
        admin = new Admin(this);
        admin->setWindowTitle("Administrator Page");
        admin->show();
    }

    else if(username == "manager" && password == "manager")
    {
        manager = new Manager(this);
        manager->setWindowTitle("Store Manager Page");
        manager->show();
    }
    else
    {
        QMessageBox::information(this, "", "Username and/or password is incorrect!");
    }

}
