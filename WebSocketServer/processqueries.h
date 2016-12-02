#ifndef PROCESSQUERIES_H
#define PROCESSQUERIES_H
#include <QThread>
#include <QRunnable>
#include "queries.h"


class ProcessQueries: public QThread
{
    Q_OBJECT
public:
    /*
     * пусть клиент вернет запись
     * будет цикл который постоянно опрашиват мою переменную
     */
    ProcessQueries(Queries* query);
    ~ProcessQueries();
    void run();
    Queries* m_queries;
    bool m_stop;
signals:
    void queryReady(Query::Ptr);
};

#endif // PROCESSQUERIES_H
