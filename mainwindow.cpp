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


void mainWindow::on_LoginButton_clicked()
{
    /***************************************************
     * Assign QString values to data entered in username
     * and password text edits
     **************************************************/
    QString username = ui -> UsernameLineEdit -> text();
    QString password = ui -> PasswordLineEdit -> text();

    /***************************************************
     * Check username and password for validation.
     * - Open Administrator page if username and
     *   password are both correct for admin use
     *
     * - Open Store manager page if username and
     *   password are both correct for store manager use
     *
     * - Display an error pop up menu if either the
     *   username and password are correct
     **************************************************/
    if(username == "admin" && password == "admin")
    {
        admin =  new Admin(this);
        admin -> setWindowTitle("Administrator Page");
        admin -> show();
    }
    else if(username == "manager" && password == "manager")
    {
        manager =  new Manager(this);
        manager -> setWindowTitle("Store Manager Page");
        manager -> show();
    }
    else
    {
        QMessageBox::information(this, "Error", "Username and/or password is incorrect!");
    }

}
