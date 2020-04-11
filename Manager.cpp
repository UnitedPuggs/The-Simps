#include "Manager.h"
#include "ui_Manager.h"

Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
}

Manager::~Manager()
{
    delete ui;
}
