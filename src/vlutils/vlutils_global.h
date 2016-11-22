#ifndef VLUTILS_GLOBAL_H
#define VLUTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VLUTILS_LIBRARY)
#  define VLUTILSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VLUTILSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VLUTILS_GLOBAL_H
