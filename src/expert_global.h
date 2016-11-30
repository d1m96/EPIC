#ifndef EXPERT_GLOBAL_H
#define EXPERT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EXPERT_LIBRARY)
#  define EXPERTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EXPERTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EXPERT_GLOBAL_H
