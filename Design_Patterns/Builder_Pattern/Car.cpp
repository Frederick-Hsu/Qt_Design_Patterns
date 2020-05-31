#include "Car.h"

#include <iostream>

void Car::SetManufactory(const string &manufactory)
{
    m_strManufactory = manufactory;
}

const string& Car::GetManufactory() const
{
    return m_strManufactory;
}

void Car::SetEngine(const string &engine)
{
    m_strEngine = engine;
}

const string& Car::GetEngine() const
{
    return m_strEngine;
}

void Car::SetChassis(const string &chassis)
{
    m_strChassis = chassis;
}

const string& Car::GetChassis() const
{
    return m_strChassis;
}

void Car::SetWheel(const string &wheel)
{
    m_strWheel = wheel;
}

const string& Car::GetWheel() const
{
    return m_strWheel;
}

void Car::PrintInfo()
{
    cout << m_strManufactory.c_str() << " "
         << m_strEngine.c_str() << " "
         << m_strChassis.c_str() << " "
         << m_strWheel.c_str()
         << endl;
}
