#include "../include/generator.h"
#include "gtest/gtest.h"


TEST(test_generator, generate_vector) {
    Generator gen(3);
    std::vector<std::pair<float, float>> result_vec = gen.get_coordinates();
    std::vector<std::pair<float, float>> expected_vec = {{48.123, 9.456}, {49.678, 9.567}};

    ASSERT_EQ(expected_vec.size(), result_vec.size()) << "Vectors expected_vec and result_vec are of unequal length";

    for (int i = 0; i < result_vec.size(); ++i) {
        EXPECT_EQ(expected_vec[i], result_vec[i]) << "Vectors expected_vec and result_vec differ at index " << i;
    }
}
