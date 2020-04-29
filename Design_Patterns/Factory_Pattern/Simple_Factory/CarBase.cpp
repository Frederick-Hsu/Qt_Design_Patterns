#include "CarBase.h"

#include <iostream>

CarBase::CarBase() : m_manufacturerName(string())
{
    cout << "called constructor CarBase::CarBase()" << endl;
}

CarBase::CarBase(const string& name) : m_manufacturerName(name)
{
    cout << "called constructor CarBase::CarBase(const string&)" << endl;
}

CarBase::~CarBase()
{
    cout << "called destructor CarBase::~CarBase()" << endl;
}

void CarBase::PrintName()
{
    cout << "The carmaker name: " << m_manufacturerName << endl;
}
