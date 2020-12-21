#include "QArrayData.hpp"

void* QArrayData::data()
{
    return reinterpret_cast<char*>(this) + offset;
}

const void* QArrayData::data() const
{
    return reinterpret_cast<const char*>(this) + offset;
}

bool QArrayData::isMutable() const
{
    return alloc != 0;
}

size_t QArrayData::detachCapacity(size_t newSize) const
{
    if (capacityReserved && newSize < alloc)
        return alloc;
    return newSize;
}

QArrayData* QArrayData::sharedNull() noexcept
{
    return const_cast<QArrayData*>(shared_null);
}
