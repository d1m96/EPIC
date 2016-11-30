#ifndef MANAGER_H
#define MANAGER_H
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "manager_global.h"
#include <checklist.h>
#include <schedule.h>
#include <mediadata.h>
#include <users.h>

class MANAGERSHARED_EXPORT Manager
{

public:
   typedef  QSharedPointer <Manager> Ptr;
    Manager();
    ~Manager();

    QVector<QString> take_equipment();
    QVector<QString> take_doc(int equip_id);
    Users::Ptr take_info_about_workers(QString department);
    Checklist::Ptr take_check_list_template(int equip_id);
    Schedule::Ptr take_tasks();

    Schedule::Ptr take_task_time(QString task,int user_id);
    Mediadata::Ptr take_mediadata_from_filled_check_lists(QString equip_type);
    Mediadata::Ptr take_mediadata_from_check_list(int user_id);

    void add_task(QString task, int user_id);
    void add_schedule(Schedule* schedule);
    void add_check_list_template(Checklist* c);
};

#endif // MANAGER_H
