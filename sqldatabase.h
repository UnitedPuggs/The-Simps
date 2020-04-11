#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include "header.h"

class sqlDatabase
{
private:
    QSqlDatabase database;

public:
    sqlDatabase();
    ~sqlDatabase();

    void createDatabase();

};

#endif // SQLDATABASE_H
