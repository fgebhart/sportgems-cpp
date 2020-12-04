#include "../include/generator.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_generator, verify_coordinates) {
    Generator gen(3, 2.0);
    gen.generate_track();
    Coordinates result_vec = gen.get_coordinates();
    Coordinates expected_vec = {{40.001, 10}, {40.003, 10}, {40.005, 10}};

    ASSERT_COORDINATES_VEC_EQ(expected_vec, result_vec);
}

TEST(test_generator, verify_times) {
    Generator gen(3, 2.0);
    gen.generate_track();
    Times result_vec = gen.get_times();
    Times expected_vec = {1, 3, 5};

    ASSERT_TIMES_VEC_EQ(expected_vec, expected_vec);
}
