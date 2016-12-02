#ifndef DBLIB_H
#define DBLIB_H
#include <memory>
#include "dblib_global.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug> 
#include <specialist.h>
#include <manager.h>
#include <expert.h>

class DBLIBSHARED_EXPORT Dblib
{

private:
    QString username;
    QString password;

public:

    typedef QSharedPointer<Dblib> Ptr;
    Dblib();
    ~Dblib();

    //QSharedPointer <Dblib> *dblib;

    int initialization(const QString username, const QString password, Manager::Ptr& mng);
    int initialization(const QString username, const QString password, Specialist::Ptr& spcl);
    int initialization(const QString username, const QString password, Expert::Ptr& exp);


    Users::Ptr test();
};

#endif // DBLIB_H
