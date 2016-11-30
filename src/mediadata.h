#ifndef MEDIADATA_H
#define MEDIADATA_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "mediadata_global.h"
#include <media_str.h>

class MEDIADATASHARED_EXPORT Mediadata
{

    QString equip_type;

public:
    typedef QSharedPointer <Mediadata> Ptr;
    QVector<media_str> mediadata;
    void set_equip_type(QString _equip_type);
    int size();


    Mediadata();
    ~Mediadata();
};

#endif // MEDIADATA_H
