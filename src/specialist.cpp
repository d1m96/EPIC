#include "specialist.h"


Specialist::Specialist()
{}

Specialist::~Specialist()
{}

QVector<QString> Specialist::take_doc(int equip_id)
{
    QSqlQuery query;
    query.prepare("SELECT doc_info FROM documentations WHERE equip_id = :equip_id;");
    query.bindValue(":equip_id", equip_id);
    query.exec();
    QVector<QString> doc_info;
    while (query.next())
    {
        doc_info.push_back(query.value(0).toString());
    }
    return doc_info;
}

Schedule::Ptr Specialist::take_own_schedule(int user_id)
{
    QSqlQuery query;
    query.prepare("SELECT shedule_id, task, time, status, check_list_id "
                  "FROM schedule WHERE executor_id = :user_id;");
    query.bindValue(":user_id",user_id);
    query.exec();
    Schedule::Ptr sched ( new Schedule );
    Sched_str sched_str;
    while (query.next())
    {
        sched->sched_id = query.value(0).toInt();
        sched_str.set_task(query.value(0).toString());
        sched_str.set_time(query.value(0).toFloat());
        sched_str.set_status(query.value(0).toString());
        sched_str.set_executor_id(query.value(0).toInt());
        sched_str.set_checklist_id(query.value(0).toInt());
        sched->schedule.push_back(sched_str);
    }
    return sched;
}

Schedule::Ptr Specialist::take_department_schedule(QString department)
{
    QSqlQuery query;
    query.prepare("SELECT shed_id, task, time, status, executor_id, check_list_id "
                  "FROM schedule WHERE department = :department;");
    query.bindValue(":department",department);
    query.exec();
    Schedule::Ptr sched ( new Schedule );
    Sched_str sched_str;
    while (query.next())
    {
        sched->sched_id = query.value(0).toInt();
        sched_str.set_task(query.value(0).toString());
        sched_str.set_time(query.value(0).toFloat());
        sched_str.set_status(query.value(0).toString());
        sched_str.set_executor_id(query.value(0).toInt());
        sched_str.set_checklist_id(query.value(0).toInt());
        sched->schedule.push_back(sched_str);
    }
    return sched;
}

Schedule::Ptr Specialist::take_tasks(int user_id)
{
    QSqlQuery query;
    query.prepare("SELECT task FROM schedule WHERE executor = :user_id AND status = 0;");
    query.bindValue(":user_id",user_id);
    query.exec();
    Schedule::Ptr sched ( new Schedule );
    Sched_str sched_str;
    while (query.next())
    {
        sched_str.set_executor_id(query.value(0).toInt());
        sched_str.set_task(query.value(0).toString());
        sched->schedule.push_back(sched_str);
    }

    return sched;
}

Checklist::Ptr Specialist::take_check_list(int user_id, QString task, QSqlDatabase db)
{
    QSqlQuery query(db);
    query.prepare("SELECT param_id, param_name, value FROM params "
                  "JOIN schedule ON executor_id = :user_id "
                  "AND task = :task "
                  "WHERE params.check_list_id = schedule.check_list_id;");
    query.bindValue(":user_id",user_id);
    query.bindValue(":task",task);
    query.exec();
    Checklist::Ptr checklist (new Checklist);
    while(query.next())
    {
        Param* p = new Param;
        p->set_id(query.value(0).toInt());
        p->set_name(query.value(1).toString());
        p->set_value(query.value(2).toString());
        checklist->param.push_back(p);
    }


    checklist->user_id = user_id;
    checklist->task = task;

    int n = checklist->size();                 // так как params будет расширяться в цикле for


    for(int i = 0; i < n; ++i)
    {
        int id = checklist->param[i]->ret_id();
        Param* it = checklist->param[i];

        while(true)
        {
            Param* p = new Param;

            query.prepare("SELECT parent_id FROM params WHERE param_id = :id;");
            query.bindValue(":id",id);
            query.exec();

            query.next();

            int id_parent = query.value(0).toInt();

            if(id_parent == NULL)
            {
                it->set_parent(NULL);
                break;
            }

            p->set_id(id_parent);

            query.prepare("SELECT param_name, value FROM params WHERE param_id = :id;");
            query.bindValue(":id",id_parent);
            query.exec();

            query.next();

            p->set_name(query.value(0).toString());
            p->set_value(query.value(1).toString());

            int j = 0;
            while(j < checklist->size())
            {
                if(p->ret_id() == checklist->param[j]->ret_id()) break;
                j++;
            }

            if(j >= checklist->size())
            {
                checklist->param.push_back(p);
                Param* t = checklist->param.last();
                it->set_parent(t);
                it = t;
            }
            else
            {
                Param* t = checklist->param[j];
                it->set_parent(t);
                it = t;
            }

            id = id_parent;

        }

    }

    return checklist;
}
/*
void Specialist::add_check_list_info(Checklist* c)
{
    QSqlQuery query;
    for (QVector<Param*>::iterator it = c->param.begin() ; it != c->param.end(); ++it)
    {
        query.prepare("INSERT INTO params (parameter_id, value) VALUES (:parameter_id, :value);");
        query.bindValue(":parameter_id",it->ret_id());
        query.bindValue(":value",it->ret_value());
        query.exec();
    }
}
*/

void Specialist::add_work_time(Checklist* c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO schedule (time) VALUES (:time) WHERE (task = :task, user_id = :user_id);");
    query.bindValue(":time",c->time);
    query.bindValue(":task",c->task);
    query.bindValue(":user_id",c->user_id);
    query.exec();
}
