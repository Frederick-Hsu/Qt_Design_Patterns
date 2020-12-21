#ifndef QFLAGS_HPP
#define QFLAGS_HPP

/*================================================================================================*/

    /* Includes: */
    #include <type_traits>
    #include <initializer_list>

    #include "QGloabl.hpp"

/*================================================================================================*/

    /* Prototypes: */
    class QFlag;
    template<typename Enum> class QFlags;

/*================================================================================================*/

    /* Macros: */
    #define Q_DECLARE_FLAGS(Flags, Enum)    typedef QFlags<Enum> Flags;

/*================================================================================================*/

    /* Definitions: */
    class QFlag
    {
        int i;
    public:
        constexpr inline QFlag(int value) noexcept;
        constexpr inline operator int() const noexcept;
        constexpr inline QFlag(uint value) noexcept;
        constexpr inline QFlag(short value) noexcept;
        constexpr inline QFlag(ushort value) noexcept;
        constexpr inline operator uint() const noexcept;
    };

    template<typename Enum> class QFlags
    {
        static_assert((sizeof(Enum) <= sizeof(int)), "QFlags uses an int as storage, so an enum with underlying long long will overflow.");
        static_assert((std::is_enum<Enum>::value), "QFlags is only usable on enumeration types.");

        struct Private;
        typedef int (Private::*Zero);

        typedef typename std::conditional<std::is_unsigned<typename std::underlying_type<Enum>::type>::value,
                                          unsigned int,
                                          signed int>::type Int;
        typedef Enum enum_type;

        constexpr inline QFlags() noexcept;
        constexpr inline QFlags(Enum flags) noexcept;
        constexpr inline QFlags(Zero) noexcept;
        constexpr inline QFlags(QFlag flag) noexcept;
        constexpr inline QFlags(std::initializer_list<Enum> flags) noexcept;

        inline QFlags& operator&=(int mask) noexcept;
        inline QFlags& operator&=(uint mask) noexcept;
    private:
        Int i;
    private:
        constexpr static inline Int initializer_list_helper(typename std::initializer_list<Enum>::const_iterator it,
                                                            typename std::initializer_list<Enum>::const_iterator end);
    };


/*================================================================================================*/

    /* Implementations: */
    template<typename Enum> constexpr QFlags<Enum>::QFlags() noexcept : i(0)
    {
    }

    template<typename Enum> constexpr QFlags<Enum>::QFlags(Enum flags) noexcept : i(Int(flags))
    {
    }

    template<typename Enum> constexpr QFlags<Enum>::QFlags(Zero) noexcept : i(0)
    {
    }

    template<typename Enum> constexpr QFlags<Enum>::QFlags(QFlag flag) noexcept : i(flag)
    {
    }

    template<typename Enum> constexpr QFlags<Enum>::QFlags(std::initializer_list<Enum> flags) noexcept
        : i(initializer_list_helper(flags.begin(), flags.end()))
    {

    }

    template<typename Enum>
    constexpr typename QFlags<Enum>::Int QFlags<Enum>::initializer_list_helper(typename std::initializer_list<Enum>::const_iterator it,
                                                                               typename std::initializer_list<Enum>::const_iterator end)
    {
        return ( (it == end) ? Int(0) : (Int(*it) | initializer_list_helper(it+1, end)) );
    }

    template<typename Enum> QFlags<Enum>& QFlags<Enum>::operator&=(int mask) noexcept
    {
        i &= mask;
        return *this;
    }

    template<typename Enum> QFlags<Enum>& QFlags<Enum>::operator&=(uint mask) noexcept
    {
        i &= mask;
        return *this;
    }
#endif  /* QFLAGS_HPP */
