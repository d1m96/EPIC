#ifndef PARAM_GLOBAL_H
#define PARAM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PARAM_LIBRARY)
#  define PARAMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PARAMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PARAM_GLOBAL_H
