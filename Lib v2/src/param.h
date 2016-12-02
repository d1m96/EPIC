#ifndef PARAM_H
#define PARAM_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "param_global.h"

class PARAMSHARED_EXPORT Param
{
    int param_id;
    QString param_name;
    Param* parent;
    QString value;


public:
    void set_id(int _id);
    void set_name(QString _name);
    void set_value(QString _value);
    void set_parent(Param* p);
    QVector<Param> children;
    int get_id();
    QString get_name();
    QString get_value();
    Param* get_parent();
    Param();
    Param(int _id, QString _name, QString _value, Param* p);
    ~Param();


};

#endif // PARAM_H
