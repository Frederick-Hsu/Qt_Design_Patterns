#ifndef MANAGER_H
#define MANAGER_H

    #include "CSingletonPtr.h"

    class Manager;

    class Manager : CSingletonPtr<Manager>
    {
    public:
        Manager();
        ~Manager();
    private:
        int m_count;
    public:
        void Print();
    };

#endif  /* MANAGER_H */
