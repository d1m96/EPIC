#include "manager.h"


Manager::Manager()
{}

Manager::~Manager()
{

}

QVector<QString> Manager::take_equipment()
{
    QSqlQuery query;
    query.exec("SELECT equip_name FROM equipment;");
    QVector<QString> equip;
    while (query.next())
    {
        equip.push_back(query.value(0).toString());
    }
    return equip;
}

QVector<QString> Manager::take_doc(int equip_id)
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

Users::Ptr Manager::take_info_about_workers(QString department)
{
    QSqlQuery query;
    query.prepare("SELECT user_id, surname, name, patronymic, role, qualification, login, password FROM users WHERE users.department_name = :department;");
    query.bindValue(":department",department);
    query.exec();
    Users::Ptr users( new Users() );
    while (query.next())
    {
        Users::user u;
        u.set_id(query.value(0).toInt());
        u.set_surname(query.value(0).toString());
        u.set_name(query.value(0).toString());
        u.set_patronymic(query.value(0).toString());
        u.set_role(query.value(0).toString());
        u.set_qualification(query.value(0).toString());
        u.set_login(query.value(0).toString());
        u.set_password(query.value(0).toString());
        users->u.push_back(u);
    }
    return users;
}

Checklist::Ptr Manager::take_check_list_template(int equip_id)
{
    QSqlQuery query;
    query.prepare("SELECT param_id, param_name, value FROM params_template"
                  "JOIN check_lists_template ON equipment = :equip_id "
                  "WHERE params_template.check_list_id = check_lists_template.check_list_id;");
    query.bindValue(":equip_id",equip_id);
    query.exec();
    Checklist::Ptr checklist ( new Checklist );
    while(query.next())
    {
        Param p;
        p.set_id(query.value(0).toInt());
        p.set_name(query.value(0).toString());
        p.set_value(query.value(0).toString());
        checklist->param.push_back(p);
    }

    //checklist->user_id = user_id;
    //checklist->task = task;
    Param _p = checklist->param.takeFirst();
    int id = _p.get_id();

    QVector<Param>::iterator i = checklist->param.end();                 // так как params будет расширяться в цикле for

    for(QVector<Param>::iterator it = checklist->param.begin() ; it != i; ++it)
    {
        while(true)
        {
            query.prepare("SELECT parent_id, param_name, value FROM params_template WHERE param_id = :id;");
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
}

Schedule::Ptr Manager::take_tasks()
{
    QSqlQuery query;
    query.exec("SELECT user_id, tasks FROM users WHERE tasks != NULL;");
    Schedule::Ptr schedule ( new Schedule );
    while (query.next())
    {
        Sched_str sch_str;

        sch_str.set_executor_id(query.value(0).toInt());
        sch_str.set_task(query.value(0).toString());

        schedule->schedule.push_back(sch_str);
    }
    return schedule;
}

Schedule::Ptr Manager::take_task_time(QString task, int user_id)
{
    QSqlQuery query;
    query.prepare("SELECT task, time FROM schedule WHERE user_id = :user_id, task = :task");
    query.bindValue(":user_id",user_id);
    query.bindValue(":task",task);
    query.exec();
    Schedule::Ptr schedule ( new Schedule );
    while (query.next())
    {
        Sched_str sch_str;

        sch_str.set_task(query.value(0).toString());
        sch_str.set_time(query.value(0).toFloat());

        schedule->schedule.push_back(sch_str);
    }
    return schedule;
}

Mediadata::Ptr Manager::take_mediadata_from_filled_check_lists(QString equip_type)
{
    QSqlQuery query;
    query.prepare("SELECT check_list_media.mediadata_id as id, mediadata.media_name as name, mediadata.reference as reference "
                  "FROM check_lists WHERE equip_type = :equip_type "
                  "JOIN check_list_media ON check_lists.check_list_id = check_list_media.check_list_id "
                  "JOIN mediadata ON check_list_media.mediadata_id = mediadata.media_id ");
    query.bindValue(":equip_type",equip_type);
    query.exec();
    Mediadata::Ptr mediadata (new Mediadata);
    while (query.next())
    {
        media_str m_str;

        m_str.set_id(query.value(0).toInt());
        m_str.set_name(query.value(0).toString());
        m_str.set_reference(query.value(0).toString());

        mediadata->mediadata.push_back(m_str);
    }
    return mediadata;
}

Mediadata::Ptr Manager::take_mediadata_from_check_list(int check_list_id)
{
    QSqlQuery query;
    query.prepare("SELECT check_list_media.mediadata_id as id, mediadata.media_name as name, mediadata.reference as reference "
                  "FROM check_lists WHERE equip_type = :equip_type "
                  "JOIN check_list_media ON check_lists.check_list_id = check_list_media.check_list_id "
                  "JOIN mediadata ON check_list_media.mediadata_id = mediadata.media_id ");

    //query.bindValue(":equip_type",equip_type); ???
    query.exec();
    Mediadata::Ptr mediadata (new Mediadata);
    while (query.next())
    {
        media_str m_str;

        m_str.set_id(query.value(0).toInt());
        m_str.set_name(query.value(0).toString());
        m_str.set_reference(query.value(0).toString());

        mediadata->mediadata.push_back(m_str);
    }
    return mediadata;
}

void Manager::add_task(QString task, int user_id)
{
    //(в задании чек-листы???)
    QSqlQuery query;
    query.prepare("INSERT INTO schedule (task,executor) VALUES(:task,:user_id);");
    query.bindValue(":user_id",user_id);
    query.bindValue(":task",task);
    query.exec();
}

void Manager::add_schedule(Schedule* schedule)
{
    for(int i = 0; i < schedule->size(); i++)
    {
        add_task(schedule->schedule.takeAt(i).get_task(), schedule->schedule.takeAt(i).get_executor_id());
    }
}

void Manager::add_check_list_template(Checklist* c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO check_list_template ???");
    query.exec();
    int i = 0;
    while(i < c->size())
    {
        query.prepare("INSERT INTO params_template (param_t_id, equip_type, param_name, parent_id, check_list_id(???), value) "
                      "VALUES (:param_t_id, :equip_type, :param_name, :parent_id, :check_list_id, :value);");
        query.bindValue(":param_t_id",c->param.takeAt(i).get_id());
        //query.bindValue(":equip_type",c->equip_type);
        query.bindValue(":param_name",c->param.takeAt(i).get_name());
        //query.bindValue(":parent_id",c->param.takeAt(i).ret_p_id());
        //query.bindValue(":check_list_id");//???
        query.bindValue(":value",c->param.takeAt(i).get_value());
        query.exec();
        i++;
    }
}


