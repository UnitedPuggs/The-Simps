#ifndef MAINMENU_H
#define MAINMENU_H

#include "header.h"

namespace Ui {
class mainMenu;
}

class mainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr);
    ~mainMenu();

private:
    Ui::mainMenu *ui;
};

#endif // MAINMENU_H
