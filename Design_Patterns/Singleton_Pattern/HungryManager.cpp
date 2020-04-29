#include "HungryManager.h"

HungryManager::HungryManager() : CHungrySingleton<HungryManager>()
{
    cout << "HungryManager constructor begins" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));;
    m_count = 0;
    cout << "HungryManager constructor ends." << endl;
}

HungryManager::~HungryManager()
{
    cout << "HungryManager destructs." << endl;
}

int HungryManager::Print(int basenum)
{
    cout << "Hi, this is HungryManager, m_count = " << ++m_count << endl;
    return m_count + basenum;
}
