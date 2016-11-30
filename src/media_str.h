#ifndef MEDIA_STR_H
#define MEDIA_STR_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>

class media_str
{

    int id;
    QString name;
    QString reference;

public:
    void set_id(int _id);
    void set_name(QString _name);
    void set_reference(QString _reference);

    int ret_id();
    QString ret_name();
    QString ret_reference();

    media_str();
    ~media_str();
};

#endif // MEDIA_STR_H
