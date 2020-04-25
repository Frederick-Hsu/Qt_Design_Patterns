#ifndef CSINGLETON_H
#define CSINGLETON_H

    class CSingleton;

    class CSingleton
    {
    public:
        static CSingleton* GetInstance();
        static void ReleaseInstance();

        void Print();
    private:
        CSingleton();
        CSingleton(const CSingleton& other);
        CSingleton& operator=(const CSingleton& other);
        virtual ~CSingleton();
    private:
        static CSingleton* m_instance;
    };

#endif  /* CSINGLETON_H */