#ifndef CHECKLIST_H
#define CHECKLIST_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "checklist_global.h"
#include <param.h>


class CHECKLISTSHARED_EXPORT Checklist
{

public:

    int checklist_id;
    QString checklist_name;
    int user_id;
    QString task;
    QVector<Param*> param;
    float time;
    QString equip_type;

   // Param* ret_pointer(int index);

    int size();

    typedef QSharedPointer <Checklist> Ptr;

    Checklist();
    ~Checklist();

};

#endif // CHECKLIST_H
