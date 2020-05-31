/* File name    : main.cpp
 * Description  : Implements the main() entry function here.
 *
 */


#include <iostream>
#include "testing.h"

int main()
{
    std::cout << "C++ standard no.: " << __cplusplus << std::endl;

    execute_test_items();
    return 0;
}