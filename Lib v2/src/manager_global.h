#ifndef MANAGER_GLOBAL_H
#define MANAGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MANAGER_LIBRARY)
#  define MANAGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MANAGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MANAGER_GLOBAL_H
