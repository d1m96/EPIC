#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QtSql>
class DataBase
{
public:
    DataBase();
    QString func(QString login, QString pas);
    QString mess(QString message);
    static initialize();
};

#endif // DATABASE_H
