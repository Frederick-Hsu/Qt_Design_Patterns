#include "Abstract_Factory.h"
#include "Car_Categories.h"

BusinessCarBase* BMWFactory::CreateBusinessCar()
{
    return (new BMWBusinessCar());
}

SportCarBase* BMWFactory::CreateSportCar()
{
    return (new BMWSportCar());
}

BusinessCarBase* BenzFactory::CreateBusinessCar()
{
    return (new BenzBusinessCar());
}

SportCarBase* BenzFactory::CreateSportCar()
{
    return (new BenzSportCar());
}

void AbstractFactoryTest(void)
{
    BusinessCarBase* pBusinessCar = nullptr;
    SportCarBase*    pSportCar    = nullptr;

    BMWFactory bmwFac;
    BenzFactory benzFac;

    pBusinessCar = bmwFac.CreateBusinessCar();
    pBusinessCar->PrintName();
    delete pBusinessCar;

    pSportCar = bmwFac.CreateSportCar();
    pSportCar->PrintName();
    delete pSportCar;

    pBusinessCar = benzFac.CreateBusinessCar();
    pBusinessCar->PrintName();
    delete pBusinessCar;

    pSportCar = benzFac.CreateSportCar();
    pSportCar->PrintName();
    delete pSportCar;
}
