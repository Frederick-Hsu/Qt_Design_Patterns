#include "test.h"
#include "SignatureDemo.h"
#include "Date.h"
#include "Complex.h"

#include <iostream>

void executeTestCases(void)
{
    testSignatureDemoFunctionOveload();
    std::cout << "\n" << std::endl;
    passOptionalArguments();
    std::cout << "\n" << std::endl;
    testOperatorOverload();
}
