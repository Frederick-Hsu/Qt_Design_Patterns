#include "CarBuilder.h"
#include "Car.h"

void GMCarBuilder::BuildManufactory()
{
    m_car.SetManufactory("GM corp.");
}

void GMCarBuilder::BuildEngine()
{
    m_car.SetEngine("Rolls-Royce engine");
}

void GMCarBuilder::BuildChassis()
{
    m_car.SetChassis("GM chassis");
}

void GMCarBuilder::BuildWheel()
{
    m_car.SetWheel("Michelin tyre");
}

void FordCarBuilder::BuildManufactory()
{
    m_car.SetManufactory("Ford corp.");
}

void FordCarBuilder::BuildEngine()
{
    m_car.SetEngine("Rolls-Royce engine");
}

void FordCarBuilder::BuildChassis()
{
    m_car.SetChassis("Mercedes-Benz chassis");
}

void FordCarBuilder::BuildWheel()
{
    m_car.SetWheel("Bridgestone tyre");
}

Car* CarDirector::BuilderCar(CarBuilderBase *pBuilder)
{
    return pBuilder->Build();
}
