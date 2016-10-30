#include "dblib.h"


Dblib::Dblib()
{
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydb");
    db.setUserName("test_user");
    db.setPassword("qwerty");
    bool connectioncheck = db.open();
    if (connectioncheck == true){
        qDebug() << "Connection to database established." << endl;
    } else {
        qDebug() << "Error for database " << db.databaseName() << " :" << db.lastError().text() << endl;
    }
    db.close();
}
Dblib::~Dblib(){

}

void Dblib::send(){
    QSqlQuery query;
    query.exec("SELECT * from user2;");
}
/*
int Dblib::inicialisize(Dblib::Ptr db)
{
    db( new Dblib() );
}
int Dblib::uninicialisize()
{

}
*/
