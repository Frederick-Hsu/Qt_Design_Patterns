#include "Extend_Abstract_Factory.h"
#include "Car_Categories.h"

#include <iostream>
using namespace std;

void BMWTruckCar::PrintName()
{
    cout << "This is BMW truck car" << endl;
    TruckCarBase::PrintName();
}

void BenzTruckCar::PrintName()
{
    cout << "This is Benz truck car" << endl;
    TruckCarBase::PrintName();
}

BusinessCarBase* BenzExtendedFactory::CreateBusinessCar()
{
    return factory.CreateBusinessCar();
}

SportCarBase* BenzExtendedFactory::CreateSportCar()
{
    return factory.CreateSportCar();
}

TruckCarBase* BenzExtendedFactory::CreateTruckCar()
{
    return (new BenzTruckCar());
}

BusinessCarBase* BMWExtendedFactory::CreateBusinessCar()
{
    return factory.CreateBusinessCar();
}

SportCarBase* BMWExtendedFactory::CreateSportCar()
{
    return factory.CreateSportCar();
}

TruckCarBase* BMWExtendedFactory::CreateTruckCar()
{
    return new BMWTruckCar();
}

void ExtendedAbstractFactoryTest(void)
{
    BusinessCarBase* pBCar = nullptr;
    SportCarBase* pSCar = nullptr;
    TruckCarBase* pTCar = nullptr;

    BMWExtendedFactory bmwFactory;
    BenzExtendedFactory benzFactory;

    pBCar = bmwFactory.CreateBusinessCar();
    pBCar->PrintName();
    delete pBCar;
    cout << endl;

    pSCar = bmwFactory.CreateSportCar();
    pSCar->PrintName();
    delete pSCar;
    cout << endl;

    pTCar = bmwFactory.CreateTruckCar();
    pTCar->PrintName();
    delete pTCar;
    cout << endl;

    pBCar = benzFactory.CreateBusinessCar();
    pBCar->PrintName();
    delete pBCar;
    cout << endl;

    pSCar = benzFactory.CreateSportCar();
    pSCar->PrintName();
    delete pSCar;
    cout << endl;

    pTCar = benzFactory.CreateTruckCar();
    pTCar->PrintName();
    delete pTCar;
    cout << endl;
}
