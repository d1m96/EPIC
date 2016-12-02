#ifndef SCHED_STR_H
#define SCHED_STR_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>

class Sched_str
{
    QString task;
    float time;
    QString status;
    int executor_id;
    int check_list_id;

public:
    void set_task(QString _task);
    void set_time(float _time);
    void set_status(QString _status);
    void set_executor_id(int _id);
    void set_checklist_id(int _id);

    QString get_task();
    int get_executor_id();

    Sched_str();
    ~Sched_str();

};

#endif // SCHED_STR_H
