#ifndef MANAGER_H
#define MANAGER_H

    #include "CSingletonPtr.h"

    #define DECLARE_SINGLETON_CLASS(type)     friend class CSingletonPtr<type>;

    class Manager;

    class Manager : public CSingletonPtr<Manager>
    {
        // friend class CSingletonPtr<Manager>;
    protected:
        Manager();
        ~Manager();
    private:
        int m_count;
    public:
        void Print();
    };

#endif  /* MANAGER_H */
