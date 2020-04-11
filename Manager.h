#ifndef MANAGER_H
#define MANAGER_H

#include "header.h"

namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H
