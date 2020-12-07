#include "../include/geo.h"
#include "gtest/gtest.h"


TEST(test_geo, to_rad) {
    double result;
    double expected;

    result = to_rad(180.0);
    expected = PI;
    EXPECT_EQ(expected, result);

    result = to_rad(90.0);
    expected = PI/2;
    EXPECT_EQ(expected, result);

    result = to_rad(263.1);
    expected = 4.591961261997081;
    EXPECT_EQ(expected, result);
}

TEST(test_geo, calculate_distance) {
    Coordinate coorA;
    Coordinate coorB;
    double result;
    double expected;
    
    // test random distance between random coordinates
    coorA = {48.123, 9.456};
    coorB = {49.678, 9.567};
    result = calculate_distance(coorA, coorB);
    expected = 173291.22;
    ASSERT_FLOAT_EQ(expected, result);

    // test distance of two coordinates with 1 meter distance
    coorA = {48.0, 8.0};
    coorB = {48.0, 8.0000135};
    result = calculate_distance(coorA, coorB);
    expected = 1.0147612213981296;
    ASSERT_DOUBLE_EQ(expected, result);

    // test distance of two equal coordinates
    coorA = {48.0, 8.0};
    coorB = {48.0, 8.0};
    result = calculate_distance(coorA, coorB);
    expected = 0.0;
    ASSERT_DOUBLE_EQ(expected, result);
}
