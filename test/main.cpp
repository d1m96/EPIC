#include <memory>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <dblib.h>
#include <specialist.h>

int main()
{
    Dblib database;
    Specialist::Ptr spcl (new Specialist);
    QString username = "root";
    QString password = "123456";
    QSqlDatabase db = database.initialization(username,password,spcl);
    Checklist::Ptr checklist (new Checklist);

    checklist = spcl->take_check_list(0,"Проверить питание воздушного насоса",db);

    return 0;

}
