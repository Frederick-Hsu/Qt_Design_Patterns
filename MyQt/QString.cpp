#include "QString.hpp"

QString::QString() noexcept : d(Data::sharedNull())
{
}

QString::~QString()
{
    if (!d->ref.deref())
    {
        Data::deallocate(d);
    }
}
