#include "Car.h"

#include <iostream>

GMCar::GMCar() : CarBase("GM")
{
}

void GMCar::PrintName()
{
    cout << "GMCar test" << endl;
    CarBase::PrintName();
}

FordCar::FordCar() : CarBase("Ford")
{
}

void FordCar::PrintName()
{
    cout << "FordCar test" << endl;
    CarBase::PrintName();
}

ToyotaCar::ToyotaCar() : CarBase("Toyota")
{
}

void ToyotaCar::PrintName()
{
    cout << "ToyotaCar test" << endl;
    CarBase::PrintName();
}
