#ifndef SPECIALIST_H
#define SPECIALIST_H
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <schedule.h>
#include <sched_str.h>
#include <checklist.h>
#include "specialist_global.h"

class SPECIALISTSHARED_EXPORT Specialist
{

public:
    typedef QSharedPointer <Specialist> Ptr;
    Specialist();
    ~Specialist();

    QVector<QString> take_doc(int equip_id);
    Schedule::Ptr take_own_schedule(int user_id);
    Schedule::Ptr take_department_schedule(QString department);
    Schedule::Ptr take_tasks(int user_id);
    Checklist::Ptr take_check_list(int user_id, QString task, QSqlDatabase db);

    void add_check_list_info(Checklist* c);
    void add_work_time(Checklist* c);

};

#endif // SPECIALIST_H
