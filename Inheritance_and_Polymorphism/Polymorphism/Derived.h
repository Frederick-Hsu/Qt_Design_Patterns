#ifndef DERIVED_H
#define DERIVED_H

    #include "Base.h"

    class Derived : public Base
    {
    public:
        Derived();
        virtual void a();
        void b();
        void c();
    };


#endif  /* DERIVED_H */