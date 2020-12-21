#ifndef QSTRING_LITERAL_HPP
#define QSTRING_LITERAL_HPP

    #include "QGloabl.hpp"
    #include "QArrayData.hpp"

    typedef QTypedArrayData<ushort> QStringData;

    typedef char16_t qunicodechar;
    static_assert(sizeof(qunicodechar) == 2, "qunicodechar must typedef an integral type of size 2");

#endif  /* QSTRING_LITERAL_HPP */
