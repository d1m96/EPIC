#ifndef DBLIB_H
#define DBLIB_H
#include <memory>
#include "dblib_global.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>

class DBLIBSHARED_EXPORT Dblib
{

public:
    std::shared_ptr<Dblib> Ptr;
    Dblib();
    ~Dblib();
    void send();

    int DBLIBSHARED_EXPORT inicialisize();
    int DBLIBSHARED_EXPORT uninicialisize();

};

#endif // DBLIB_H
