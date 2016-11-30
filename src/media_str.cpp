#include "media_str.h"

media_str::media_str()
{

}

media_str::~media_str()
{

}
void media_str::set_id(int _id)
{
    id = _id;
}

void media_str::set_name(QString _name)
{
    name = _name;
}

void media_str::set_reference(QString _reference)
{
    reference = _reference;
}

int media_str::ret_id()
{
    return id;
}

QString media_str::ret_name()
{
    return name;
}

QString media_str::ret_reference()
{
    return reference;
}
