#include "processqueries.h"
#include "QDebug"

ProcessQueries::ProcessQueries(Queries* query):m_stop(false)
{
    //?

}

ProcessQueries::~ProcessQueries()
{

}


/*
 * прочитал, остановился, прочитал дальше
 * надеюсь правильно
 */
void ProcessQueries::run()
{
    while(!m_stop)
    {
        if(m_queries->empty())
            continue;

        Query::Ptr query = m_queries->getNextQuery();
        if(query)
        {
            query->exec();
            emit queryReady(query);
        }
        //emit queryRead( Qu:Ptr query );
    }
}
