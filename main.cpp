#include "mainwindow.h"
#include "sqldatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow window;
    sqlDatabase database;
    database.createDatabase();
    window.show();

    return a.exec();
}
