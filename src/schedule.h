#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <sched_str.h>
#include "schedule_global.h"


class SCHEDULESHARED_EXPORT Schedule
{
public:

    typedef QSharedPointer <Schedule> Ptr;
    int sched_id;
    QVector <Sched_str> schedule;
    Schedule();
    ~Schedule();

    int size();
};

#endif // SCHEDULE_H
