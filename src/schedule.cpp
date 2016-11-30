#include "schedule.h"


Schedule::Schedule()
{

}

Schedule::~Schedule()
{

}

int Schedule::size()
{
    int i = 0;
    for (QVector<Sched_str>::iterator it = schedule.begin(); it != schedule.end(); ++it, i++);
    return i;
}
