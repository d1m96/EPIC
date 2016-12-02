#include "checklist.h"


int Checklist::get_chl_id()
{
    return checklist_id;
}

void Checklist::set_chl_id(int id)
{
    checklist_id = id;
}

QString Checklist::get_chl_name()
{
    return checklist_name;
}

void Checklist::set_chl_name(QString name)
{
    checklist_name = name;
}

int Checklist::get_user_id()
{
    return user_id;
}

void Checklist::set_user_id(int id)
{
    user_id = id;
}

QString Checklist::get_task()
{
    return task;
}

void Checklist::set_task(QString _task)
{
    task = _task;
}

float Checklist::get_time()
{
    return time;
}

void Checklist::set_time(float _time)
{
    time = _time;
}

QString Checklist::get_equipment()
{
    return equipment;
}

void Checklist::set_equipment(QString _equip)
{
    equipment = _equip;
}


int Checklist::size()
{
    param.size();
}
//создаем параметр в виде XML
QDomElement parametr(      QDomDocument& domDoc,
                    const int&      strID,
                    const QString&      strName,
                    const QString&      strValue
                   )
{
    QDomElement domElement = domDoc.createElement("parametr");
    QDomAttr IdAttr = domDoc.createAttribute("id");
    IdAttr.setValue(QString::number(strID));
    domElement.setAttributeNode(IdAttr);
    QDomAttr NameAttr = domDoc.createAttribute("name");
    NameAttr.setValue(strName);
    domElement.setAttributeNode(NameAttr);
    QDomAttr ValueAttr = domDoc.createAttribute("value");
    ValueAttr.setValue(strValue);
    domElement.setAttributeNode(ValueAttr);
    return domElement;
}
void Create_Tree(QDomDocument doc,QDomElement parent, Param* child) //Создание вложенности
{
    QDomElement parm = parametr(doc,child->get_id(),child->get_name(),child->get_value());
    parent.appendChild(parm);
    if(!child->children.empty())
    {
        for(int i=0;i<child->children.size();i++)
            Create_Tree(doc,parm,&child->children[i]);
    }
}
QString Checklist::MakeXML() //создание XML
{
        QDomDocument doc(checklist_name);
        QDomElement  domElement = doc.createElement(checklist_name);
        doc.appendChild(domElement);
        // далее добавление дерева параметров в domElement
        foreach (Param p, param) {
            Create_Tree(doc,domElement,&p);
        }
        //далее идет создание необходимой вложенности параметров
   //     QDomElement parm = parametr(doc,param[0].get_id(),param[0].get_name(),param[0].get_value());
   //     domElement.appendChild(parm);

        return doc.toString();
}

Checklist::Checklist()
{
}
/*
Checklist::Checklist(int _checklist_id, QString _checklist_name, int _user_id, float _time, QString _equip_type)
{

}
*/
