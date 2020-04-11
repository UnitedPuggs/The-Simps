#include "mainmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainMenu window;
    window.show();

    return a.exec();
}
