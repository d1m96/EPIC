#include "specialist.h"


Specialist::Specialist()
{}

Specialist::~Specialist()
{}
/*
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

Checklist::Ptr Specialist::take_check_list(int user_id, QString task)
{
    QSqlQuery query;
    query.prepare("SELECT param_id, param_name, value FROM params "
                  "JOIN schedule ON executor = :user_id "
                  "AND task = :task "
                  "WHERE params.check_list_id = schedule.check_list;");
    query.bindValue(":user_id",user_id);
    query.bindValue(":task",task);
    query.exec();
    Checklist::Ptr checklist (new Checklist);
    while(query.next())
    {
        Param p;
        p.set_id(query.value(0).toInt());
        p.set_name(query.value(0).toString());
        p.set_value(query.value(0).toString());
        checklist->param.push_back(p);
    }


    checklist->user_id = user_id;
    checklist->task = task;
    Param _p = checklist->param.takeFirst();
    int id = _p.get_id();

    QVector<Param>::iterator i = checklist->param.end();                 // так как params будет расширяться в цикле for

    for(QVector<Param>::iterator it = checklist->param.begin() ; it != i; ++it)
    {
        while(true)
        {
            query.prepare("SELECT parent_id, param_name, value FROM params WHERE param_id = :id;");
            query.bindValue(":id",id);
            query.exec();

            Param p;

            int id_2 = query.value(0).toInt();
            if(id_2 == NULL)
                break;

            p.set_id(id_2);
            p.set_name(query.value(0).toString());
            p.set_value(query.value(0).toString());

            checklist->param.push_back(p);
            Param t = checklist->param.takeLast();
            it->set_parent(&t);

            id = id_2;
        }
    }

    return checklist;
}*/
struct Parametr
{
public:
    int param_id;
    QString param_name;
    QString value;
    int parent_id;
};
void Create_children(Param* parm, QVector<Parametr>& params)
{
    for (int i=0;i<params.size();i++)
    {
        if(params[i].parent_id == parm->get_id())
        {
            Param* p = new Param();
            p->set_id(params[i].param_id);
            p->set_name(params[i].param_name);
            p->set_value(params[i].value);
            p->set_parent(parm);
            parm->children.append(*p);
            params.removeAt(i);
            i--;
        }
    }
    if(!parm->children.empty())
    {
        foreach (Param p, parm->children) {
            Create_children(&p,params);
        }
    }
}

Checklist::Ptr Specialist::take_check_list(int checklist_id)
{
    QSqlQuery query;
    query.prepare("SELECT param_id, param_name, value, parent_id"
                  "FROM params"
                  "WHERE checklist_id = :checklist_id"
                  );
    query.bindValue(":checklist_id",checklist_id);
    query.exec();
    Checklist::Ptr checklist;
    QVector<Parametr> params;
    while(query.next())
    {
        Parametr* p = new Parametr();
        p->param_id=(query.value(0).toInt());
        p->param_name=(query.value(1).toString());
        p->value=(query.value(2).toString());
        p->parent_id = query.value(3).toInt();
        params.push_back(*p);
    }
    for(int i=0;i<params.size();i++)
    {

        if(params[i].parent_id==0)
        {
            Param* p = new Param();
            p->set_id(params[i].param_id);
            p->set_name(params[i].param_name);
            p->set_value(params[i].value);
            p->set_parent(NULL);
            checklist->param.push_back(*p);
            params.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<checklist->param.size();i++){
         Create_children(&checklist->param[i],params);
    }
    //названия полей и таблиц в запросах нужно проверить
       query.prepare("SELECT check_list_id, checklist_name, user_id, equip_type"
                     "FROM check_lists"
                     "WHERE checklist_id=:checklist_id"
                     );
       query.bindValue(":checklist_id",checklist_id);
       query.exec();//запрос остальных данных чек-листа
       while(query.next())
       {
         checklist->set_chl_id(query.value(0).toInt());
         checklist->set_chl_name(query.value(1).toString());
         checklist->set_user_id(query.value(2).toInt());

         checklist->set_equipment(query.value(3).toString());
       }
       return checklist;
}

/*void Specialist::add_check_list_info(Checklist* c)
{
    QSqlQuery query;
    for (QVector<Param>::iterator it = c->param.begin() ; it != c->param.end(); ++it)
    {
        query.prepare("INSERT INTO params (parameter_id, value) VALUES (:parameter_id, :value);");
        query.bindValue(":parameter_id",it->get_id());
        query.bindValue(":value",it->get_value());
        query.exec();
    }
}

void Specialist::add_work_time(Checklist* c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO schedule (time) VALUES (:time) WHERE (task = :task, user_id = :user_id);");
    query.bindValue(":time",c->time);
    query.bindValue(":task",c->task);
    query.bindValue(":user_id",c->user_id);
    query.exec();
}
*/
