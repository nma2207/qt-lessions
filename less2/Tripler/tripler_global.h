#ifndef TRIPLER_GLOBAL_H
#define TRIPLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRIPLER_LIBRARY)
#  define TRIPLERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TRIPLERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TRIPLER_GLOBAL_H
