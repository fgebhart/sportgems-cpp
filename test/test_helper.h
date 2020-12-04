#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <math.h>
#include <limits>
#include <iostream>

#include "../include/types.h"
#include "gtest/gtest.h"


#define EPSILON std::numeric_limits<double>::epsilon()

bool AreSame(double a, double b)
{
    bool result = abs(a - b) < EPSILON;
    std::cout << "a: " << a << ", b: " << b << ", Epsilon: " << EPSILON << ", result: " << result << std::endl;
    return result;
}

void ASSERT_TIMES_VEC_EQ(Times const &times_a, Times const times_b) {
    ASSERT_EQ(times_a.size(), times_b.size()) << "times vectors are of unequal length";

    for (int i = 0; i < times_b.size(); ++i) {
        EXPECT_EQ(times_a[i], times_b[i]);
    }
}

void ASSERT_ELEVATION_VEC_EQ(Elevation const &elevation_a, Elevation const elevation_b) {
    ASSERT_EQ(elevation_a.size(), elevation_b.size()) << "elevation vectors are of unequal length";

    for (int i = 0; i < elevation_b.size(); ++i) {
        ASSERT_NEAR(elevation_a[i], elevation_b[i], 0.001);
    }
}

void ASSERT_COORDINATES_VEC_EQ(Coordinates const &coordinates_a, Coordinates const &coordinates_b) {
    ASSERT_EQ(coordinates_a.size(), coordinates_b.size()) << "coordinates are of unequal length";

    for (int i = 0; i < coordinates_b.size(); ++i) {
        ASSERT_NEAR(coordinates_a[i].first, coordinates_b[i].first, 0.0001);
        ASSERT_NEAR(coordinates_a[i].second, coordinates_b[i].second, 0.0001);
    }
}
#endif
