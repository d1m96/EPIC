#include "queries.h"
#include <QDebug>

bool Queries::empty() { return vQuery.empty(); }

QString CheckListQuery::getMessage() { return m_message; }

QString SheduleQuery::getMessage() { return m_message; }

void Queries::pushQuery(Query::Ptr q) 
{
    /*
     * этот метод добавляет
     * в очередь следующий
     * элемент
     */
    m_mutex.lock();
    qDebug() << "pushQuery";
    vQuery.enqueue(q);
    m_mutex.unlock();
}

Query::Ptr Queries::getNextQuery()
{
    /*
     * этот метод получает из очереди
     * первый элемент
     */
    m_mutex.lock();
    qDebug() << "getnextQuery";
    Query::Ptr q = vQuery.dequeue();
    m_mutex.unlock();
    return q;
}

SheduleQuery::SheduleQuery(QString message)
{
    QStringList mas = message.split(":");
    m_message = mas[1];
    qDebug() << "SheduleQuery::SheduleQuery: " << message;
}

// номер кого мне нужно и номер чеклиста
CheckListQuery::CheckListQuery(QString message)
{
    //пасрю бугага
    m_message = mas[1];
}

int SheduleQuery::exec() {
    /*
     * вызываю метод либы который возвращает
     * расписание
     */

    m_message = "schedule ^_^";
    //emit queryReady(this);
    return 0;
}

int CheckListQuery::exec() {
    /*
     * вызываю метод либы который возвращает
     * чеклист
     */
    m_message = "<root></root>";
    //emit queryReady(this);
    return 0;
}

