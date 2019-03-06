#include "test.h"
#include "SignatureDemo.h"
#include "Date.h"
#include "Complex.h"
#include "function_arguments.h"

#include <iostream>

void executeTestCases(void)
{
    testSignatureDemoFunctionOveload();
    std::cout << "\n" << std::endl;
    passOptionalArguments();
    std::cout << "\n" << std::endl;
    testOperatorOverload();

    std::cout << "\n\n" << std::endl;
    verifyFunctionArgumentsModule();
}

void verifyFunctionArgumentsModule(void)
{
    testSumit();
    std::cout << "\n" << std::endl;
    testMessAround();
    std::cout << "\n" << std::endl;
    testSwap();
    std::cout << "\n" << std::endl;
    // testConstReference();
    testMaxi();
    std::cout << "\n" << std::endl;
    testConstOverload();
}
