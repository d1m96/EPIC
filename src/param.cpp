#include "param.h"


void Param::set_id(int _id)
{
    param_id = _id;
}

void Param::set_name(QString _name)
{
    param_name = _name;
}

void Param::set_value(QString _value)
{
    value = _value;
}

void Param::set_parent(Param *p)
{
    parent = p;
}

int Param::ret_id()
{
    return param_id;
}

QString Param::ret_name()
{
    return param_name;
}

QString Param::ret_value()
{
    return value;
}

bool Param::operator !=(const Param &a)
{
    if(param_id == a.param_id) return false;
    else return true;
}

bool Param::operator ==(const Param &a)
{
    if(param_id == a.param_id) return true;
    else return false;
}

Param::Param()
{
}

Param::~Param()
{
}
