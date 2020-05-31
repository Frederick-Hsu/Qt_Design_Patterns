#include "template_factory.h"
#include "../Simple_Factory/CarBase.h"
#include "../Simple_Factory/Car.h"

template<class T> T* STCarFactory::Create()
{
    return new T();
}

template<class T> CarBase* STCarBaseFactory::Create()
{
    return new T();
}

void STCarFactoryTest(void)
{
    CarBase* pCar = nullptr;
    pCar = STCarFactory::Create<GMCar>();
    pCar->PrintName();
    delete pCar;

    pCar = STCarFactory::Create<FordCar>();
    pCar->PrintName();
    delete pCar;

    pCar = STCarFactory::Create<ToyotaCar>();
    pCar->PrintName();
    delete pCar;

    pCar = nullptr;
}

void STCarBaseFactoryTest(void)
{
    CarBase* pCar = nullptr;
    pCar = STCarBaseFactory::Create<GMCar>();
    pCar->PrintName();
    delete pCar;

    pCar = STCarBaseFactory::Create<FordCar>();
    pCar->PrintName();
    delete pCar;

    pCar = STCarBaseFactory::Create<ToyotaCar>();
    pCar->PrintName();
    delete pCar;

    pCar = nullptr;
}
