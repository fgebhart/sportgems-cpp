#include "../include/gem_finder.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_gem_finder, get_vector_of_distances) {
    Coordinates coordinates;
    Distances result_distances;
    Distances expected_distances;

    // test two coordinates only
    coordinates = {{48.0, 8.0}, {48.0, 8.1}};
    result_distances = get_vector_of_distances(coordinates);
    expected_distances = {0.0, 7448.7124};
    ASSERT_VEC_OF_FLOATS_EQ(expected_distances, result_distances);

    // test more than two coordinates
    coordinates = {{48.0, 8.0}, {48.0, 8.1}, {48.0, 8.2}, {48.0, 8.3}};
    result_distances = get_vector_of_distances(coordinates);
    expected_distances = {0.0, 7448.7124, 14897.3535, 22346.0664};
    ASSERT_VEC_OF_FLOATS_EQ(expected_distances, result_distances);
}