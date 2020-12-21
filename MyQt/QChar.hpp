#ifndef QCHAR_HPP
#define QCHAR_HPP

    #include "QGloabl.hpp"

    class QChar;

    class QChar
    {
    public:
        enum SpecialCharacter
        {
            NULL = 0x0000,
            Tabulation = 0x0009,
            LineFeed = 0x000A,
            FormFeed = 0x000C,
            CarriageReturn = 0x000D,
            Space = 0x0020,
            Nbsp = 0x00A0,
            SoftHyphen = 0x00AD,
            ReplacementCharacter = 0xFFFD,
            ObjectReplacementCharacter = 0xFFFC,
            ByteOrderMark = 0xFEFF,
            ByteOrderSwapped = 0xFFFE,
            ParagraphSeparator = 0x2029,
            LineSeparator = 0x2028,
            LastValidCodePoint = 0x10FFFF
        };
        constexpr QChar() noexcept : ucs(0) {}
        constexpr QChar(ushort rc) noexcept : ucs(rc) {}
        constexpr QChar(uchar c, uchar r) noexcept : ucs(ushort( (r << 8) | c)) {}
        constexpr QChar(short rc) noexcept : ucs(ushort(rc)) {}
        constexpr QChar(uint rc) noexcept : ucs(ushort(rc & 0xFFFF)) {}
    private:
        friend constexpr bool operator==(QChar, QChar) noexcept;
        friend constexpr bool operator< (QChar, QChar) noexcept;

        ushort ucs;
    };

#endif  /* QCHAR_HPP */
