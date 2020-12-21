#ifndef QCOMPILER_HPP
#define QCOMPILER_HPP

    // #define _Pragma         prgama
    #pragma
namespace MyQt
{
    #define qt_do_pragma(text)      #pragma (#text)
    #define QT_WARNING_PUSH         QT_DO_PRAGMA(clang diagnostic push)
}


#endif  /* QCOMPILER_HPP */
