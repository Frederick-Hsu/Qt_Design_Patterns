#ifndef ICLONEABLE_H
#define ICLONEABLE_H

    #include <iostream>
    using namespace std;

    template<class ElemType> class ICloneable;
    template<class ElemType> class ICloneable2;

    template<class ElemType> class ICloneable
    {
    public:
        virtual ElemType* Clone() = 0;
    };

    template<class ElemType> class ICloneable2
    {
    public:
        virtual ElemType* Clone() = 0;
        bool IsDeepClone();
    public:
        virtual ~ICloneable2();
    protected:
        ICloneable2();
    protected:
        void SetDeepClone(bool isDeepClone);
        bool m_bIsDeepClone;
    };

    template<class ElemType> bool ICloneable2<ElemType>::IsDeepClone()
    {
        return m_bIsDeepClone;
    }

    template<class ElemType> ICloneable2<ElemType>::ICloneable2()
    {
        cout << "Called protected constructor ICloneable<T>::ICloneable2()" << endl;
        m_bIsDeepClone = false;
    }

    template<class ElemType> ICloneable2<ElemType>::~ICloneable2<ElemType>()
    {   /* empty */
    }

    template<class ElemType> void ICloneable2<ElemType>::SetDeepClone(bool isDeepClone)
    {
        m_bIsDeepClone = isDeepClone;
    }


#endif  /* ICLONEABLE_H */
