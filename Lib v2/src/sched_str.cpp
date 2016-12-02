#include "sched_str.h"

QString Sched_str::get_task()
{
    return task;
}

int Sched_str::get_executor_id()
{
    return executor_id;
}

void Sched_str::set_task(QString _task)
{
    task = _task;
}

void Sched_str::set_time(float _time)
{
    time = _time;
}

void Sched_str::set_status(QString _status)
{
    status = _status;
}

void Sched_str::set_executor_id(int _id)
{
    executor_id = _id;
}

void Sched_str::set_checklist_id(int _id)
{
    check_list_id = _id;
}


Sched_str::Sched_str()
{

}

Sched_str::~Sched_str()
{

}
