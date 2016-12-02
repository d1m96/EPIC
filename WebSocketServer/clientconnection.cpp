#include "clientconnection.h"
///#include <database.h>

ClientConnection::ClientConnection(QWebSocket *s):
 m_processQueries(0)
{
    m_queries = new Queries();
    m_processQueries.m_queries = m_queries;
    m_sock = s;

    /*
     * Тут надо подключить либу
     * проинициилизировать
     */
    DataBase::initialize();
    //database.inicilize(m_mng);
    //что то с контейнером...

    m_pChecklist = m_specialist->take_check_list(0);
    QString asdkj = m_pChecklist->MakeXML();

    //Specialist::Ptr spcl (new Specialist);
    //QSqlDataBase db = new m_db.incializatin(user,pas);
    //checklist = Checklist::Ptr(new Checklist);
 //Checklist::Ptr chechlist (new Checklist);
    //checklist = spcl->take_check_list(0,"Проверить питание", db);
    //c/hecklist
    //connect(pQueries, &ProcessQueries::finished, pQueries, &QObject::deleteLater);

    qDebug() << "ClientConnection pSocket: " << s;
    connect(s,&QWebSocket::textMessageReceived,this, &ClientConnection::reciveMessages);

    m_processQueries.start();

}

ClientConnection::~ClientConnection()
{
    m_processQueries.m_stop = true;
    m_processQueries.deleteLater(); //???
}

void ClientConnection::sendMessage(Query::Ptr query)
{
    /*
     * вызывается после того как отработал exec
     */
    qDebug()<<"сигнал получен :)";
    m_sock->sendTextMessage(query->getMessage());
}

void ClientConnection::reciveMessages(QString message)
{
    /*
     * высняю какой запрос
     * либо прям тут парсю
     * либо выываю метод который парсит
     * создать обьект запроса и добавляю в очередь
     */

    Query::Ptr query;
    QStringList mas = message.split(':');

    if(mas[0] == "CHECKLIST"){
        /*
         * вытащит чек лист с айлишником ноль
         * на следующей строке делает перевод в строку
         */
        m_pChecklist = m_specialist->take_check_list(0);
        query = Query::Ptr(new CheckListQuery(m_pChecklist->MakeXML()));

        m_queries->pushQuery(query);
        qRegisterMetaType<Query::Ptr>("Query::Ptr");
        connect(&m_processQueries, SIGNAL(queryReady(Query::Ptr)),this,SLOT(sendMessage(Query::Ptr)));


    }
    else if(mas[0] == "SHEDULE") {
        query = Query::Ptr(new SheduleQuery(message));
        m_queries->pushQuery(query);
        qRegisterMetaType<Query::Ptr>("Query::Ptr");
        connect(&m_processQueries, SIGNAL(queryReady(Query::Ptr)),this,SLOT(sendMessage(Query::Ptr)));
    }
}
