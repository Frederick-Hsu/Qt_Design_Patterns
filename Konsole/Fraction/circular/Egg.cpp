#include "Egg.h"                /* Whereas in the source file, it can allow to include multiple */
#include "Chicken.h"            /* header files, it won't incur the circular-dependency error.  */

Chicken* Egg::getParent()
{
    return (new Chicken());
}
