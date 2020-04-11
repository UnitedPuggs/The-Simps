#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow window;
    window.show();

    return a.exec();
}
