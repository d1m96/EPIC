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
    query.prepare("SELECT surname, name, patronymic, role_id, login, password FROM users;");
    query.exec();
    while(query.next())
    {
        QString a = query.value(0).toString();
        qDebug() << a;
    }


    Users::Ptr users( new Users() );
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
    return users;

}

int Dblib::initialization(const QString username, const QString password, Manager::Ptr& mng)
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
        query.prepare("SELECT role FROM users WHERE name = :username;");
        query.bindValue(":username",username);
        query.exec();
        QString role = query.value(0).toString();

        if(role == "manager")
        {
            mng = Manager::Ptr ( new Manager() ) ;
            return 1;
        }
        else
        {
            puts("Invalid role!!!");
            return 0;
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return 2;
}


Dblib::Dblib()
{}

Dblib::~Dblib()
{
}

int Dblib::initialization(const QString username, const QString password, Specialist::Ptr &spcl)
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
        query.prepare("SELECT role FROM users WHERE name = :username;");
        query.bindValue(":username",username);
        query.exec();
        QString role = query.value(0).toString();

        if(role == "specialist")
        {
            spcl = Specialist::Ptr ( new Specialist() ) ;
            return 1;
        }
        else
        {
            puts("Invalid role!!!");
            return 0;
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return 2;
}


int Dblib::initialization(const QString username, const QString password, Expert::Ptr &exp)
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
        query.prepare("SELECT role FROM users WHERE name = :username;");
        query.bindValue(":username",username);
        query.exec();
        QString role = query.value(0).toString();

        if(role == "expert")
        {
            exp = Expert::Ptr ( new Expert() ) ;
            return 1;
        }
        else
        {
            puts("Invalid role!!!");
            return 0;
        }

    }
    else
    {
        qDebug() << "Error for database " << database.databaseName() << " :" << database.lastError().text() << endl;
    }

    return 2;
}

