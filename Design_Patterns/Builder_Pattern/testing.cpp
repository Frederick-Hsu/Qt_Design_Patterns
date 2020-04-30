#include "testing.h"
#include "CarBuilder.h"

#include <memory>
using namespace std;

void execute_test_items(void)
{
    TestCarBuilder();
}

void TestCarBuilder(void)
{
    CarDirector director;
    GMCarBuilder gmBuilder;
    FordCarBuilder fordBuilder;

    Car* pcar = director.BuilderCar(&gmBuilder);
    pcar->PrintInfo();

    pcar = director.BuilderCar(&fordBuilder);
    pcar->PrintInfo();
}
