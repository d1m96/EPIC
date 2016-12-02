#ifndef CHECKLIST_H
#define CHECKLIST_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "checklist_global.h"
#include <param.h>
#include <QtXml>

class CHECKLISTSHARED_EXPORT Checklist
{
    int checklist_id;
    QString checklist_name;
    QString equipment;

public:
    int user_id;
    QString task;
    float time;

    typedef QSharedPointer<Checklist>Ptr;
    int get_chl_id();
    void set_chl_id(int id);
    QString get_chl_name();
    void set_chl_name(QString name);
    int get_user_id();
    void set_user_id(int id);
    QString get_task();
    void set_task(QString _task);
    float get_time();
    void set_time(float _time);
    QString get_equipment();
    void set_equipment(QString _equip);


    QVector<Param> param;
    int size();
    QString MakeXML();
    Checklist();
    ~Checklist();
};


#endif // CHECKLIST_H
