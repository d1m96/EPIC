#include "param.h"


void Param::set_id(int _id)
{
    param_id = _id;
}

void Param::set_name(QString _name)
{
    param_name = _name;
}

void Param::set_parent(Param *p)
{
    parent = p;
}

void Param::set_value(QString _value)
{
    value = _value;
}

int Param::get_id()
{
    return param_id;
}

QString Param::get_name()
{
    return param_name;
}

Param *Param::get_parent()
{
    return parent;
}

Param::Param()
{
}

Param::Param(int _id, QString _name, QString _value, Param *p)
{
    param_id = _id;
    param_name = _name;
    value = _value;
    parent = p;
}

QString Param::get_value()
{
    return value;
}


Param::~Param()
{
}
