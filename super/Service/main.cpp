#include <QApplication>
#include <QtCore>

#include <stdlib.h>
#include <dblib.h>

//#include "server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   // QGuiApplication::setApplicationDisplayName(Server::tr("Fortune Server"));
    //Server server;
    //server.show();
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Dblib db;
    db.send();
    return app.exec();
}