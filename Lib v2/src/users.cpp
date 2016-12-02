#include "users.h"


Users::Users()
{
}

Users::~Users()
{

}

void Users::user::set_id(int _id)
{
    user_id = _id;
}

void Users::user::set_surname(QString _surname)
{
    surname = _surname;
}

void Users::user::set_name(QString _name)
{
    name = _name;
}

void Users::user::set_patronymic(QString _patronymic)
{
    patronymic = _patronymic;
}

void Users::user::set_role(QString _role)
{
    role = _role;
}

void Users::user::set_qualification(QString _qualification)
{
    qualification = _qualification;
}

void Users::user::set_login(QString _login)
{
    login = _login;
}

void Users::user::set_password(QString _password)
{
    password = _password;
}

Users::user::user()
{

}

Users::user::~user()
{

}
