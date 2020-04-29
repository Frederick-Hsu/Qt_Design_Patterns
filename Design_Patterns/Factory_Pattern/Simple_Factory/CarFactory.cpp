#include "CarFactory.h"
#include "CarBase.h"
#include "Car.h"

#include <cassert>

CarBase* CarFactory::Create(const string &name)
{
    CarBase* car = nullptr;
    if ("GM" == name)
    {
        car = new GMCar();
    }
    else if ("Ford" == name)
    {
        car = new FordCar();
    }
    else if ("Toyota" == name)
    {
        car = new ToyotaCar();
    }
    else
    {
        assert(false);      /* pop up the error message-box */
    }
    return car;
}
