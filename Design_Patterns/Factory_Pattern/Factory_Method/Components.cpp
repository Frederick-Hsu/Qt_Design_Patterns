#include "Components.h"

#include <iostream>
using namespace std;

Engine::Engine()
{
    cout << "construct engine" << endl;
}

Engine::~Engine()
{
    cout << "destruct enginer" << endl;
}

Chassis::Chassis()
{
    cout << "construct chassis" << endl;
}

Chassis::~Chassis()
{
    cout << "destruct chassis" << endl;
}

Wheel::Wheel()
{
    cout << "construct wheel" << endl;
}

Wheel::~Wheel()
{
    cout << "destruct wheel" << endl;
}
