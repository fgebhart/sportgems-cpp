#include "../include/geo.h"
#include "gtest/gtest.h"


TEST(test_geo, to_rad) {

    double result1 = to_rad(180.0);
    double expected1 = PI;
    EXPECT_EQ(expected1, result1);

    double result2 = to_rad(90.0);
    double expected2 = PI/2;
    EXPECT_EQ(expected2, result2);

    double result3 = to_rad(263.1);
    double expected3 = 4.591961261997081;
    EXPECT_EQ(expected3, result3);
}

TEST(test_geo, calculate_distance) {
    std::cout << std::setprecision(13);
    std::pair<double, double> coor1 = {48.123, 9.456};
    std::pair<double, double> coor2 = {49.678, 9.567};
    float result = calculate_distance(coor1, coor2);
    float expected = 173290.67;
    ASSERT_FLOAT_EQ(expected, result);
}
