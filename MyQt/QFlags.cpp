#include "QFlags.hpp"

constexpr QFlag::QFlag(int value) noexcept : i(value)
{
}

constexpr QFlag::operator int() const noexcept
{
    return i;
}

constexpr QFlag::QFlag(uint value) noexcept : i(int(value))
{
}

constexpr QFlag::QFlag(short value) noexcept : i(int(value))
{
}

constexpr QFlag::QFlag(ushort value) noexcept : i(int(uint(value)))
{
}

constexpr QFlag::operator uint() const noexcept
{
    return uint(i);
}
