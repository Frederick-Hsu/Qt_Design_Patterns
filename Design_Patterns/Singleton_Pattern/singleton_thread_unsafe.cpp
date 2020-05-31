#include "singleton_thread_unsafe.h"
#include "CSingleton.h"
#include "Meyers_Singleton_Pattern.h"

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#define ORDINARY_SINGLETON      1
#define MEYERS_SINGLETON        2
#define SINGLETON_KIND          MEYERS_SINGLETON

unsigned int Singleton_Thread(void)
{
    cout << "Current thread-ID = " << this_thread::get_id() << endl;
#if (SINGLETON_KIND == ORDINARY_SINGLETON)
    CSingleton::GetInstance()->Print();

    CSingleton::ReleaseInstance();
#elif (SINGLETON_KIND == MEYERS_SINGLETON)
    MeyersSingleton::GetInstance().Print();
#endif
    return 0;
}

void Test_Multiple_Threads(void)
{
    vector<thread> threads;
    /* Create 3 threads of CSingleton */
    threads.push_back(thread(Singleton_Thread));
    threads.push_back(thread(Singleton_Thread));
    threads.push_back(thread(Singleton_Thread));

    for (vector<thread>::iterator it = threads.begin(); it != threads.end(); ++it)
    {
        it->join();
    }
}
