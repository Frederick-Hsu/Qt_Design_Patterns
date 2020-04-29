#include "test.h"

#include "Simple_Factory/CarBase.h"
#include "Simple_Factory/CarFactory.h"

#include <iostream>
#include <memory>
using namespace std;

void execute_test_items(void)
{
    SimpleFactoryTest();

}

void SimpleFactoryTest(void)
{
    CarBase* car = CarFactory::Create("GM");
    car->PrintName();
    delete car;
    cout << "\n" << endl;

    car = CarFactory::Create("Ford");
    car->PrintName();
    delete car;
    cout << "\n" << endl;

#if 0
    car = CarFactory::Create("Toyota");
    car->PrintName();
    delete car;
#else
    shared_ptr<CarBase> carptr(CarFactory::Create("Toyota"));
    carptr->PrintName();
#endif
    cout << "\n" << endl;
}
