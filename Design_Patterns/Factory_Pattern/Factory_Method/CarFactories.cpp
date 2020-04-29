#include "CarFactories.h"
#include "../Simple_Factory/CarBase.h"
#include "../Simple_Factory/Car.h"

CarBase* GMFactory::Create()
{
    return new GMCar();
}

CarBase* FordFactory::Create()
{
    return new FordCar();
}

CarBase* ToyotaFactory::Create()
{
    return new ToyotaCar();
}

void FactoryMethodTest(void)
{
    IFactory* ptrFactory = nullptr;
    CarBase* ptrCar = nullptr;

    GMFactory gmFactory;
    FordFactory fordFactory;
    ToyotaFactory toyotaFactory;

    ptrFactory = &gmFactory;
    ptrCar = ptrFactory->Create();
    ptrCar->PrintName();
    delete ptrCar;

    ptrFactory = &fordFactory;
    ptrCar = ptrFactory->Create();
    ptrCar->PrintName();
    delete ptrCar;

    ptrFactory = &toyotaFactory;
    ptrCar = ptrFactory->Create();
    ptrCar->PrintName();
    delete ptrCar;

    ptrCar = nullptr;
    ptrFactory = nullptr;
}
