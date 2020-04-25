#include "CSingleton.h"

#include <iostream>
#include <chrono>
#include <thread>

CSingleton* CSingleton::m_instance = nullptr;

CSingleton* CSingleton::GetInstance()
{
    if (nullptr == m_instance)
    {
        m_instance = new CSingleton();
    }
    return m_instance;
}

void CSingleton::ReleaseInstance()
{
    if (nullptr != m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}

CSingleton::CSingleton()
{
    std::cout << "CSingleton begins constructing." << std::endl;
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    std::cout << "CSingleton ends constructing." << std::endl;
}

CSingleton::~CSingleton()
{
    std::cout << "CSingleton destructs." << std::endl;
}

void CSingleton::Print()
{
    std::cout << "Print out CSingleton." << std::endl;
}