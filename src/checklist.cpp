#include "checklist.h"



int Checklist::size()
{
    int i = 0;
    for (QVector<Param*>::iterator it = param.begin(); it != param.end(); ++it, i++);
    return i;
}

Checklist::Checklist()
{}

Checklist::~Checklist()
{

}
/*
Checklist::Checklist(int _checklist_id, QString _checklist_name, int _user_id, float _time, QString _equip_type)
{

}
*/
