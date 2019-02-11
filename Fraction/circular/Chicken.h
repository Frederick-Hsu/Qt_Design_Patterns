#ifndef CHICKEN_H
#define CHICKEN_H

    // #include "Egg.h"     /* DO NOT use the circularly header-including */
    class Egg;              /* SHOULD use the forward class declaration */

    class Chicken
    {
    public:
        Egg* layEgg();      /* Only when using class pointer (Egg*), you can use the forward
                             * class declaration, otherwise you must include header file.
                             */
    };

#endif  /* CHICKEN_H */
