#include "AssemblingCar.h"
#include "Components.h"

#include <iostream>

AssemblingCar::AssemblingCar(Engine* pengine, Chassis* pchassis, Wheel* pwheel)
{
    m_ptrEngine.reset(pengine);
    m_ptrChassis.reset(pchassis);
    m_ptrWheel.reset(pwheel);
}

void AssemblingCar::PrintName()
{
    cout << "Assembly a car with engine, chassis and wheel." << endl;
}
