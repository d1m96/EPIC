#include "dblib.h"
#include <string>

Users::Ptr Dblib::test()
{
    qDebug() << ":)";
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("test_database");
    database.setUserName("root");
    database.setPassword("123456");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT parent_id FROM params WHERE param_id = 0;");
    query.exec();
    Users::Ptr users(new Users());
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString surname = query.value(1).toString();
        qDebug() << name << surname;
        Users::user u;
        u.set_name(name);
        u.set_surname(surname);
    }



    /*
    while (query.next())
    {
        Users::user u;
        u.set_id(query.value(0).toInt());
        query.next();
        u.set_surname(query.value(0).toString());
        query.next();
        u.set_name(query.value(0).toString());
        query.next();
        u.set_patronymic(query.value(0).toString());
        query.next();
        u.set_role(query.value(0).toString());
        query.next();
        u.set_login(query.value(0).toString());
        query.next();
        u.set_password(query.value(0).toString());
        users->u.push_back(u);

    }
    */

}

QSqlDatabase Dblib::initialization(const QString username, const QString password, Manager::Ptr& mng)
{
    qDebug() << ":)";
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("test_database");
    database.setUserName(username);
    database.setPassword(password);
    bool connectioncheck = database.open();
    if (connectioncheck == true)
    {
        qDebug() << "Connection to database established." << endl;
        QSqlQuery query;
        query.prepare("SELECT role_id FROM users WHERE login = :username");
        query.bindValue(":username",username);
        query.exec();
        int role = query.value(0).toInt();

        if(role == 1)
        {
            mng = Manager::Ptr ( new Manager() ) ;
        }
        else
        {
            puts("Invalid role!!!");
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return database;
}


Dblib::Dblib()
{}

Dblib::~Dblib()
{
}

QSqlDatabase Dblib::initialization(const QString username, const QString password, Specialist::Ptr &spcl)
{
    qDebug() << ":)";
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("test_database");
    database.setUserName(username);
    database.setPassword(password);
    bool connectioncheck = database.open();
    if (connectioncheck == true)
    {
        qDebug() << "Connection to database established." << endl;
        QSqlQuery query;
        query.prepare("SELECT role_id FROM users WHERE login = :username");
        query.bindValue(":username",username);
        query.exec();
        int role = query.value(0).toInt();

        if(role == 0)
        {
            spcl = Specialist::Ptr ( new Specialist() ) ;
        }
        else
        {
            puts("Invalid role!!!");
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return database;
}


QSqlDatabase Dblib::initialization(const QString username, const QString password, Expert::Ptr &exp)
{
    qDebug() << ":)";
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("test_database");
    database.setUserName(username);
    database.setPassword(password);
    bool connectioncheck = database.open();
    if (connectioncheck == true)
    {
        qDebug() << "Connection to database established." << endl;
        QSqlQuery query;
        query.prepare("SELECT role_id FROM users WHERE login = :username");
        query.bindValue(":username",username);
        query.exec();
        int role = query.value(0).toInt();

        if(role == 2)
        {
            exp = Expert::Ptr ( new Expert() ) ;
        }
        else
        {
            puts("Invalid role!!!");
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return database;
}

