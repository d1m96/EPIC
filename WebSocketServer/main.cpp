#include <QCoreApplication>
#include <webserver.h>
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Webserver* w = new Webserver(1234);
    QObject::connect(w,&Webserver::closed,&a,&QCoreApplication::quit);

    return a.exec();
}
