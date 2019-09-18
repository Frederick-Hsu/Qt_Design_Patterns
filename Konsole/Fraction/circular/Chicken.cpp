#include "Chicken.h"
#include "Egg.h"

Egg* Chicken::layEgg()
{
    return (new Egg());
}
