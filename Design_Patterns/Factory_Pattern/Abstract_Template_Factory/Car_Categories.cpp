#include "Car_Categories.h"

#include <iostream>
using namespace std;

BusinessCarBase::BusinessCarBase(const string& name) : CarBase(name) {}
SportCarBase::SportCarBase(const string& name) : CarBase(name) {}

BMWBusinessCar::BMWBusinessCar() : BusinessCarBase("BMW business car") {}
BMWSportCar::BMWSportCar() : SportCarBase("BMW sport car") {}
BenzBusinessCar::BenzBusinessCar() : BusinessCarBase("Benz business car") {}
BenzSportCar::BenzSportCar() : SportCarBase("Benz sport car") {}

void BMWBusinessCar::PrintName()
{
    cout << "This is BMW business car" << endl;
    BusinessCarBase::PrintName();
}

void BMWSportCar::PrintName()
{
    cout << "This is BMW sport car" << endl;
    SportCarBase::PrintName();
}

void BenzBusinessCar::PrintName()
{
    cout << "This is Mercedes-Benz business car" << endl;
    BusinessCarBase::PrintName();
}

void BenzSportCar::PrintName()
{
    cout << "This is Mercedes-Benz sport car" << endl;
    SportCarBase::PrintName();
}
