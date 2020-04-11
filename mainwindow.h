#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"

enum setIndex
{
    LOGIN_PAGE = 0,
    ADMIN_PAGE = 1,
    STOREMANAGER_PAGE = 2
};

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
