#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(setIndex::LOGIN_PAGE);
}

mainWindow::~mainWindow()
{
    delete ui;
}
