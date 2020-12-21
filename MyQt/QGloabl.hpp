#ifndef QGLOBAL_HPP
#define QGLOBAL_HPP

    template<int> struct QIntegerForSize;
    template<>    struct QIntegerForSize<1> { typedef unsigned char Unsigned;   typedef signed char Signed; };
    template<>    struct QIntegerForSize<2> { typedef unsigned short Unsigned;  typedef signed short Signed; };
    template<>    struct QIntegerForSize<4> { typedef unsigned int Unsigned;    typedef signed int Signed; };
    template<>    struct QIntegerForSize<8> { typedef unsigned long long Unsigned;  typedef signed long Signed; };


    template<class T> struct QIntegerForSizeof : QIntegerForSize<sizeof(T)> {};

    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
    typedef unsigned long ulong;

    typedef QIntegerForSizeof<void*>::Signed qptrdiff;

#endif  /* QGLOBAL_HPP */
