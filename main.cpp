#include "mainwindow.h"
#include "sqldatabase.h"
#include "administrator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow window;
    sqlDatabase database;
    administrator as;
    database.createDatabase();
    database.readFileCustomer();
    //Checking if the addCustomer works and it works so far.
    //as.addCustomer();

    window.show();

    return a.exec();
}
