#ifndef CARDS2D_GLOBAL_H
#define CARDS2D_GLOBAL_H

    #include <QtCore/qglobal.h>

    #if defined(CARDS2D_LIBRARY)
        #define CARDS2DSHARED_EXPORT Q_DECL_EXPORT
    #else
        #define CARDS2DSHARED_EXPORT Q_DECL_IMPORT
    #endif

#endif  /* CARDS2D_GLOBAL_H */
