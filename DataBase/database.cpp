#include "database.h"
#include <qdebug.h>

DataBase::DataBase()
{

}


//коннектим базу данных
DataBase::initialize()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("test_database");
    database.setUserName("root");
    database.setPassword("123456");
    database.open();
}

