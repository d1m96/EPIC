#ifndef QUERIES_H
#define QUERIES_H

#include <QVector>
#include <QStringList>
#include <QMutex>
#include <QQueue>
#include <QTime>
#include <QSharedPointer>
#include <QObject>
//#include "specialist.h"/
//#include "dblib.h"

class Query
{
public:
    typedef QSharedPointer<Query> Ptr;
    virtual int exec() = 0;
    virtual QString getMessage() = 0;
signals:
    //void queryReady( Query* );
};

/*
 * Если расписание
 * наследник абстрактного класса
 * Query
 * exec - запрос с библиотеки
 * параметры для запроса
 */
class SheduleQuery: public Query
{
public:
    QTime from;
    QTime to;
    QString getMessage();
    SheduleQuery(QString message);
    QString m_message;
    int exec();
};

/*
 * Если checklistn
 * наследник абстрактного класса
 * Query
 * exec - запрос с библиотеки
 * параметры для запроса
 */
class CheckListQuery: public Query
{
public:
    CheckListQuery(QString message);
    int exec();
    QString getMessage();

private:
    QString m_message;
};

/*
 * запросы заносятся в очередь
 * по принципу первый пришел, первый вышел
 * метод pushQuery добавляет в очередь
 * метод getNextQuery получает из очереди
 */
class Queries
{
    QMutex m_mutex;
    QQueue<Query::Ptr> vQuery;

public:
    bool empty();
    void pushQuery(Query::Ptr q);
    Query::Ptr getNextQuery();
};
#endif // QUERIES_H
