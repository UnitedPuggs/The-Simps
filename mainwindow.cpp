#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(640, 480));
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
        ui->UsernameLineEdit->setText("");
        ui->PasswordLineEdit->setText("");
    }

    else if(username == "manager" && password == "manager")
    {
        manager = new Manager(this);
        manager->setWindowTitle("Store Manager Page");
        manager->show();
        ui->UsernameLineEdit->setText("");
        ui->PasswordLineEdit->setText("");
    }
    else
    {
        QMessageBox::information(this, "", "Username and/or password is incorrect!");
    }

}
