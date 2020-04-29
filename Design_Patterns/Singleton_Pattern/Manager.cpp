#include "Manager.h"

Manager::Manager() : CSingletonPtr<Manager>()
{
#if defined (DEBUG_PURPOSE)
    cout << "Manager begins constructing..." << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
#endif
    m_count = 0;
#if defined (DEBUG_PURPOSE)
    cout << "Manager ends constructing." << endl;
#endif
}

Manager::~Manager()
{
#if defined (DEBUG_PURPOSE)
    cout << "Manager destructs." << endl;
#endif
}

void Manager::Print()
{
#if defined (DEBUG_PURPOSE)
    cout << "Hi, I am the Manager, m_count = " << m_count << endl;
#endif
}
