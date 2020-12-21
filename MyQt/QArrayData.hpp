#ifndef QAARAY_DATA_HPP
#define QAARAY_DATA_HPP

    #include <cstddef>
    #include <cassert>

    #include "QGloabl.hpp"
    #include "QFlags.hpp"

    struct QArrayData;
    template<class T> struct QTypedArrayData;

    struct QArrayData
    {
        int size;
        uint alloc : 31;
        uint capacityReserved : 1;
        qptrdiff offset;

        void* data();
        const void* data() const;
        bool isMutable() const;

        enum AllocationOption
        {
            CapacityReserved = 0x01,
            Unsharable      = 0x02,
            RawData         = 0x04,
            Grow            = 0x08,
            Default         = 0
        };

        Q_DECLARE_FLAGS(AllocationOptions, AllocationOption)

        size_t detachCapacity(size_t newSize) const;
        static QArrayData* sharedNull() noexcept;

        static const QArrayData shared_null[2];
    };

    template<class T> struct QTypedArrayData : QArrayData
    {
        typedef T* iterator;
        typedef const T* const_iterator;

        T* data();
        const T* data() const;

        iterator begin(iterator = iterator());
        iterator end(iterator = iterator());
        const_iterator begin(const_iterator = const_iterator()) const;
        const_iterator end(const_iterator = const_iterator()) const;
        const_iterator constBegin(const_iterator = const_iterator()) const;
        const_iterator constEnd(const_iterator = const_iterator()) const;

        class AlignmentDummy
        {
            QArrayData head;
            T data;
        };

        static QTypedArrayData* allocate(size_t capacity, AllocationOptions options = Default);
        static QTypedArrayData* reallocateUnaligned(QTypedArrayData* data, size_t capacity, AllocationOptions options = Default);

        static QTypedArrayData* sharedNull() noexcept;
    };

    template<class T> T* QTypedArrayData<T>::data()
    {
        return static_cast<T*>(QArrayData::data());
    }

    template<class T> const T* QTypedArrayData<T>::data() const
    {
        return static_cast<const T*>(QArrayData::data());
    }

    template<class T> typename QTypedArrayData<T>::iterator QTypedArrayData<T>::begin(iterator)
    {
        return data();
    }

    template<class T> typename QTypedArrayData<T>::iterator QTypedArrayData<T>::end(iterator)
    {
        return data() + size;
    }

    template<class T> QTypedArrayData<T>* QTypedArrayData<T>::sharedNull() noexcept
    {
        assert(sizeof(QTypedArrayData) == sizeof(QArrayData));
        return static_cast<QTypedArrayData*>(QArrayData::sharedNull());
    }

#endif  /* QAARAY_DATA_HPP */
