#ifndef BASE_H
#define BASE_H

    class Base
    {
    public:
        Base();
        virtual ~Base()
        {
        }
        void a();
        virtual void b();
        virtual void c(bool condition = true);
    };

#endif  /* BASE_H */