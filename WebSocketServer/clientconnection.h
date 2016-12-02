#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H
#include <database.h>
#include <QObject>
#include <QWebSocket>
#include <processqueries.h>
#include <queries.h>
#include <specialist.h>
#include <checklist.h>

//#include "dblib.h"
//#include "specialist.h"
class ClientConnection: public QObject
{
    Q_OBJECT
public:
    ClientConnection(QWebSocket* s);
    //Queries* m_pQueries;
    ~ClientConnection();

private slots:
    void reciveMessages(QString message);
    void sendMessage(Query::Ptr query);

private:
    //DataBase m_db;
    //Checklist* m_checklist;
    QWebSocket* m_sock;
    Queries* m_queries;
    ProcessQueries m_processQueries; //не лучше pq* m_pc ?? чтобы связать сигнал завершения
    Specialist::Ptr m_specialist;
    Checklist*  m_pChecklist;

};

#endif // CLIENTCONNECTION_H
