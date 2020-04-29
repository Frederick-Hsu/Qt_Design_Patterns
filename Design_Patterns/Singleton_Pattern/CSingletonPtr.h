/* File name    : CSingletonPtr.h
 * Description  : 实现一个线程安全的单例模式
 */

#ifndef CSINGLETONPTR_H
#define CSINGLETONPTR_H

    #define DEBUG_PURPOSE   1

    #include <memory>
#if defined (DEBUG_PURPOSE)
    #include <iostream>
    #include <thread>
    #include <chrono>
#endif
    #include <mutex>
    using namespace std;

    template<class T> class CSingletonPtr;

    template<class T> class CSingletonPtr
    {
    private:
        static std::shared_ptr<T> m_singletonPtr;
    protected:
        CSingletonPtr();
        virtual ~CSingletonPtr();
    private:
        CSingletonPtr& operator=(const CSingletonPtr& other);
        CSingletonPtr(const CSingletonPtr& other);
    public:
        static shared_ptr<T> GetInstance();
        static T& GetElementInstance();
    private:
        class Deleter
        {
        public:
            void operator()(T* p);
        };
    };



/*=================================================================================================*/

    template<class T> shared_ptr<T> CSingletonPtr<T>::m_singletonPtr;

    template<class T> CSingletonPtr<T>::CSingletonPtr()
    {
        #if defined (DEBUG_PURPOSE)
        cout << "CSingletonPtr begins constructing..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "CSingletonPtr ends." << endl;
        #endif
    }

    template<class T> CSingletonPtr<T>::~CSingletonPtr<T>()
    {
        #if defined (DEBUG_PURPOSE)
        cout << "CSingletonPtr destructs..." << endl;
        #endif
    }

    template<class T> shared_ptr<T> CSingletonPtr<T>::GetInstance()
    {
        mutex m_mutex;
        lock_guard<mutex> lockGuard(m_mutex);
        shared_ptr<T> tmp(new T(), T::Deleter());
        m_singletonPtr = tmp;
        return m_singletonPtr;
    }

    template<class T> T& CSingletonPtr<T>::GetElementInstance()
    {
        mutex mtx;
        lock_guard<mutex> lockGuard(mtx);
        shared_ptr<T> tmp(new T(), T::Deleter());
        m_singletonPtr = tmp;
        return m_singletonPtr.get();
    }

    template<class T> void CSingletonPtr<T>::Deleter::operator()(T* p)
    {
        delete p;
    }

#endif  /* CSINGLETONPTR_H */