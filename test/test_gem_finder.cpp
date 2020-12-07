#include "../include/gem_finder.h"
#include "test_helper.h"
#include "gtest/gtest.h"
#include "../include/generator.h"
#include "../include/parser.h"
#include "../include/exceptions.h"


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

TEST(test_gem_finder, get_number_of_unique_elements) {
    std::vector<int> vec = {1, 2, 2, 2, 3};
    int result = get_number_of_unique_elements(vec);
    int expected = 3;
    EXPECT_EQ(expected, result);
}

TEST(test_gem_finder, check_if_data_does_change_at_all) {
    std::vector<int> vec;
    // does not throw an exception
    vec = {1, 2, 2, 2, 3};
    check_if_data_does_change_at_all(vec);

    // does throw an error
    bool caught_exception = false;
    vec = {2, 2, 2, 2, 2};
    try {
        check_if_data_does_change_at_all(vec);
    } catch(DataQualityError) {
        caught_exception = true;
    }
    assert(caught_exception);

}

TEST(test_gem_finder, find_gems__with_generator) {
    // generate a dummy track, which is kind of short and only includes 3 fastest distances
    Segment track = generate_track({10, 10, 10}, {1.0, 1.1, 1.0});
    Results results = find_gems(track);

    // manually create expected results
    Results expected_results;
    Result result_1, result_2, result_3;
    result_1.fastest_distance = 1000;
    result_2.fastest_distance = 2000;
    result_3.fastest_distance = 3000;
    result_1.start_index = 9;
    result_2.start_index = 9;
    result_3.start_index = 3;
    result_1.end_index = 17;
    result_2.end_index = 25;
    result_3.end_index = 28;
    result_1.velocity_found = 122.299;
    result_2.velocity_found = 118.158;
    result_3.velocity_found = 115.674;
    expected_results.push_back(result_1);
    expected_results.push_back(result_2);
    expected_results.push_back(result_3);
    ASSERT_RESULTS_EG(expected_results, results);
}

TEST(test_gem_finder, find_gems__with_parser) {
    // parse tiny gpx test file
    XMLParser parser("../test/data/tiny.gpx");
    Segment track = parser.parse_file();
    Results results = find_gems(track);

    // manually create expected results
    Results expected_results;
    Result result_1, result_2, result_3, result_5, result_10;
    result_1.fastest_distance = 1000;
    result_2.fastest_distance = 2000;
    result_3.fastest_distance = 3000;
    result_5.fastest_distance = 5000;
    result_10.fastest_distance = 10000;
    result_1.start_index = 0;
    result_2.start_index = 0;
    result_3.start_index = 0;
    result_5.start_index = 0;
    result_10.start_index = 0;
    result_1.end_index = 1;
    result_2.end_index = 1;
    result_3.end_index = 1;
    result_5.end_index = 1;
    result_10.end_index = 2;
    result_1.velocity_found = 1811.092;
    result_2.velocity_found = 1811.092;
    result_3.velocity_found = 1811.092;
    result_5.velocity_found = 1811.092;
    result_10.velocity_found = 1811.083;
    expected_results.push_back(result_1);
    expected_results.push_back(result_2);
    expected_results.push_back(result_3);
    expected_results.push_back(result_5);
    expected_results.push_back(result_10);
    ASSERT_RESULTS_EG(expected_results, results);
}