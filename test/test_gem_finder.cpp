#include "../include/gem_finder.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_gem_finder, get_vector_of_distances) {
    Coordinates coordinates = {{48.0, 8.0}, {48.0, 8.1}};
    Distances result_distances = get_vector_of_distances(coordinates);
    // using just two 
    Distances expected_distances = {0.0, 7448.7124};
    ASSERT_VEC_OF_FLOATS_EQ(expected_distances, result_distances);
}