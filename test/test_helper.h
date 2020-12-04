#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <math.h>
#include <limits>
#include <iostream>

#define EPSILON std::numeric_limits<double>::epsilon()

bool AreSame(double a, double b)
{
    bool result = abs(a - b) < EPSILON;
    std::cout << "a: " << a << ", b: " << b << ", Epsilon: " << EPSILON << ", result: " << result << std::endl;
    return result;
}

#endif
