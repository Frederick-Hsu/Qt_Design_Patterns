#ifndef CHUNGRY_SINGLETON_H
#define CHUNGRY_SINGLETON_H

    #include <iostream>
    #include <thread>
    #include <chrono>
    using namespace std;

    template<class ElemType> class CHungrySingleton;

    template<class ElemType> class CHungrySingleton
    {
    public:
        static ElemType& GetInstance();
    protected:
        CHungrySingleton();
        virtual ~CHungrySingleton();
    private:
        CHungrySingleton(const CHungrySingleton&);
        CHungrySingleton& operator=(const CHungrySingleton&);
    private:
        static ElemType selem;
    };

    template<class ElemType> ElemType CHungrySingleton<ElemType>::selem;

    template<class ElemType> ElemType& CHungrySingleton<ElemType>::GetInstance()
    {
        return selem;
    }

    template<class ElemType> CHungrySingleton<ElemType>::CHungrySingleton()
    {
        cout << "Begin constructor CHungrySingleton()" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "End constructor CHungrySingleton()" << endl;
    }

    template<class ElemType> CHungrySingleton<ElemType>::~CHungrySingleton()
    {
        cout << "CHungrySingleton destructs" << endl;
    }

#endif  /* CHUNGRY_SINGLETON_H */
