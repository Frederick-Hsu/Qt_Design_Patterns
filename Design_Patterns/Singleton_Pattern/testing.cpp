#include "testing.h"
#include "singleton_thread_unsafe.h"
#include "HungryManager.h"

#include <vector>

void execute_test_items(void)
{
    // Test_Multiple_Threads();
    test_multithreading_for_hungry_mode_singleton();
}

unsigned int hungry_mode_singleton_task(int basenum)
{
    // cout << "Thread #" << basenum << " has thread-id = " << this_thread::get_id() << endl;
    int num = HungryManager::GetInstance().Print(basenum);
    return num;
}

void test_multithreading_for_hungry_mode_singleton(void)
{
    vector<thread> thdvec;
    thdvec.push_back(thread(hungry_mode_singleton_task, 1));
    cout << "Thread #" << thdvec[0].get_id() << " had been created." << endl;
    thdvec.push_back(thread(hungry_mode_singleton_task, 2));
    cout << "Thread #" << thdvec[1].get_id() << " had been created." << endl;
    thdvec.push_back(thread(hungry_mode_singleton_task, 3));
    cout << "Thread #" << thdvec[2].get_id() << " had been created." << endl;

    for (auto it = thdvec.begin(); it != thdvec.end(); ++it)
    {
        it->join();
    }
}
