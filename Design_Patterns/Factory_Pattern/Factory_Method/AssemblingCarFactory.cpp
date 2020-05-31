#include "AssemblingCarFactory.h"
#include "../Simple_Factory/CarBase.h"
#include "AssemblingCar.h"
#include "Components.h"


CarBase* AssemblingCarFactory::Create()
{
    return (new AssemblingCar(new Engine, new Chassis, new Wheel));
}

void AssemblingCarFactoryTest(void)
{
    AssemblingCarFactory factory;
    CarBase* pCar = factory.Create();
    pCar->PrintName();
    delete pCar;
    pCar = nullptr;
}
