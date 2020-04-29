#ifndef MEYERS_SINGLETON_PATTERN_H
#define MEYERS_SINGLETON_PATTERN_H

    class MeyersSingleton;

    class MeyersSingleton
    {
    public:
        static MeyersSingleton& GetInstance();
        void Print();
    private:
        int m_count;
        MeyersSingleton();
        ~MeyersSingleton();
    private:
        MeyersSingleton(const MeyersSingleton& other);
        MeyersSingleton& operator=(const MeyersSingleton& other);
    };

#endif  /* MEYERS_SINGLETON_PATTERN_H */
