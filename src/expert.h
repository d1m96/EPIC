#ifndef EXPERT_H
#define EXPERT_H
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "expert_global.h"
#include <param.h>
#include <checklist.h>
#include <mediadata.h>

class EXPERTSHARED_EXPORT Expert
{

public:
    typedef QSharedPointer <Expert> Ptr;

    Expert();
    ~Expert();


    QVector<QString> take_doc(int equip_id);
    Checklist::Ptr take_check_list_template(int equip_id);
    Mediadata::Ptr take_mediadata_from_filled_check_lists(QString equip_type);

    void add_check_list_template(Checklist* c);
    void add_doc(QString name_doc, QString info);
    void add_media(Mediadata* m);
};

#endif // EXPERT_H
