#ifndef SCHEDULE_GLOBAL_H
#define SCHEDULE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SCHEDULE_LIBRARY)
#  define SCHEDULESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SCHEDULESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SCHEDULE_GLOBAL_H
