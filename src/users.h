#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include "users_global.h"
#include <memory>

class USERSSHARED_EXPORT Users
{
public:
    class user
    {
        int user_id;
        QString surname;
        QString name;
        QString patronymic;
        QString role;
        QString qualification;
        QString login;
        QString password;

    public:
        void set_id(int _id);
        void set_surname(QString _surname);
        void set_name(QString _name);
        void set_patronymic(QString _patronymic);
        void set_role(QString _role);
        void set_qualification(QString _qualification);
        void set_login(QString _login);
        void set_password(QString _password);

        user();
        ~user();
    };


    typedef std::shared_ptr<Users> Ptr;

    QVector<user> u;
    Users();
    ~Users();

};

#endif // USERS_H
