#include "test.h"

#include "Simple_Factory/CarBase.h"
#include "Simple_Factory/CarFactory.h"
#include "Abstract_Template_Factory/template_factory.h"
#include "Factory_Method/AssemblingCarFactory.h"
#include "Abstract_Template_Factory/Abstract_Factory.h"
#include "Abstract_Template_Factory/Extend_Abstract_Factory.h"

#include <iostream>
#include <memory>
using namespace std;

void execute_test_items(void)
{
//    SimpleFactoryTest();
//    cout << "\n" << endl;

//    STCarFactoryTest();
//    cout << "\n" << endl;

//    STCarBaseFactoryTest();
//    cout << "\n" << endl;

//    AssemblingCarFactoryTest();
//    cout << "\n" << endl;

//    AbstractFactoryTest();
//    cout << "\n" << endl;

    ExtendedAbstractFactoryTest();
    cout << "\n" << endl;
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
