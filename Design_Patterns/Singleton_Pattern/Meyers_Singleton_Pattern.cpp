#include "Meyers_Singleton_Pattern.h"

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

MeyersSingleton& MeyersSingleton::GetInstance()
{
    static MeyersSingleton s_meyers;
    return s_meyers;
}

void MeyersSingleton::Print()
{
    cout << "Print MeyersSingleton count = " << m_count << endl;
}

MeyersSingleton::MeyersSingleton()
{
    cout << "Begin construct MeyersSingleton count = " << m_count << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    m_count = 100;
    cout << "End construct MeyersSingleton count = " << m_count << endl;
}

MeyersSingleton::~MeyersSingleton()
{
    cout << "MeyersSingleton destruct." << endl;
}
