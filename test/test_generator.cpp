#include "../include/generator.h"
#include "gtest/gtest.h"


TEST(test_generator, verify_coordinates) {
    Generator gen(3, 2.0);
    gen.generate_track();
    std::vector<std::pair<float, float>> result_vec = gen.get_coordinates();
    std::vector<std::pair<float, float>> expected_vec = {{40.001, 10}, {40.003, 10}, {40.005, 10}};

    ASSERT_EQ(expected_vec.size(), result_vec.size()) << "Vectors expected_vec and result_vec are of unequal length";

    for (int i = 0; i < result_vec.size(); ++i) {
        ASSERT_NEAR(expected_vec[i].first, result_vec[i].first, 0.001);
        ASSERT_NEAR(expected_vec[i].second, result_vec[i].second, 0.001);
    }
}

