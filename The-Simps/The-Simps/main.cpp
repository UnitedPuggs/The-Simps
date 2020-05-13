#include "sqldatabase.h"
#include "mainwindow.h"
#include "Manager.h"
#include "Admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow window;
    sqlDatabase temp;
    temp.createDatabase();
 //   temp.readFileCustomer();
 //   temp.readFileSales();
    window.show();

    return a.exec();
}
