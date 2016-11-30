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

    int ret_id();
    QString ret_name();
    QString ret_value();
    bool operator !=(const Param& a);
    bool operator ==(const Param& a);


    Param();
    ~Param();


};

#endif // PARAM_H
