#include "expert.h"



Expert::Expert()
{

}

Expert::~Expert()
{

}

QVector<QString> Expert::take_doc(int equip_id)
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
}

Checklist::Ptr Expert::take_check_list_template(int equip_id)
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

Mediadata::Ptr Expert::take_mediadata_from_filled_check_lists(QString equip_type)
{
    QSqlQuery query;
    query.prepare("SELECT check_list_media.mediadata_id as id, mediadata.media_name as name, mediadata.reference as reference "
                  "FROM check_lists WHERE equip_type = :equip_type "
                  "JOIN check_list_media ON check_lists.check_list_id = check_list_media.check_list_id "
                  "JOIN mediadata ON check_list_media.mediadata_id = mediadata.media_id ");
    query.bindValue(":equip_type",equip_type);
    query.exec();
    Mediadata::Ptr m_data( new Mediadata );
    while (query.next())
    {
        media_str m_str;

        m_str.set_id(query.value(0).toInt());
        m_str.set_name(query.value(0).toString());
        m_str.set_reference(query.value(0).toString());

        m_data->mediadata.push_back(m_str);
    }
    return m_data;
}

void Expert::add_check_list_template(Checklist* checklist)   //??? как организовать вставку параметров
{
    QSqlQuery query;
    query.prepare("INSERT INTO check_list_template (checklist_name, equip_type) "
                  "VALUES (:checklist_name, :equip_type); ");
    //query.bindValue(":checklist_name",checklist->checklist_name);
    //query.bindValue(":equip_type",checklist->equip_type);
    query.exec();
    int i = 0;
    while(i < checklist->size())
    {
        query.prepare("INSERT INTO params_template (param_t_id, equip_type, param_name, parent_id, check_list_id(???), value) "
                      "VALUES (:param_t_id, :equip_type, :param_name, :parent_id, :check_list_id, :value);");
        query.bindValue(":param_t_id",checklist->param[i].get_id());
        //query.bindValue(":equip_type",checklist->equip_type);
        query.bindValue(":param_name",checklist->param[i].get_name());
        //query.bindValue(":parent_id",checklist->param[i].ret_p_id());
        //query.bindValue(":check_list_id");//???
        query.bindValue(":value",checklist->param[i].get_value());
        query.exec();
        i++;
    }

}

void Expert::add_doc(QString doc_name, QString doc_info)
{
    QSqlQuery query;
    query.prepare("INSERT INTO documentations (doc_name, doc_info) VALUES (:doc_name, :doc_info);");
    query.bindValue(":doc_name",doc_name);
    query.bindValue(":doc_info",doc_info);
    query.exec();
}

void Expert::add_media(Mediadata* m)
{
    QSqlQuery query;
    int i = 0;
    while(i < m->size())
    {
        query.prepare("INSERT INTO mediadata (media_id, media_name, reference) "
                      "VALUES (:id, :name, :reference);");
        query.bindValue(":id",m->mediadata[i].ret_id());
        query.bindValue(":name",m->mediadata[i].ret_name());
        query.bindValue(":reference",m->mediadata[i].ret_reference());
        query.exec();
        i++;
    }
}


