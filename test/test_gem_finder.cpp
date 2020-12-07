#include "gtest/gtest.h"

#include "test_helper.h"
#include "../include/gem_finder.h"
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
    expected_distances = {0.0, 7448.6841};
    ASSERT_VEC_OF_FLOATS_EQ(expected_distances, result_distances);

    // test more than two coordinates
    coordinates = {{48.0, 8.0}, {48.0, 8.1}, {48.0, 8.2}, {48.0, 8.3}};
    result_distances = get_vector_of_distances(coordinates);
    expected_distances = {0.0, 7448.6841, 14897.3682, 22346.0523};
    ASSERT_VEC_OF_FLOATS_EQ(expected_distances, result_distances);
}

TEST(test_gem_finder, get_number_of_unique_elements) {
    // test using integers
    EXPECT_EQ(3, get_number_of_unique_elements({1, 2, 2, 2, 3}));

    // test using floats
    EXPECT_EQ(3, get_number_of_unique_elements({1.0, 2.1, 2.1, 2.1, 3.7}));
}

TEST(test_gem_finder, check_if_data_does_change_at_all) {
    // does not throw an exception
    check_if_data_does_change_at_all({1.0, 2.0, 2.0, 2.0, 3.0});

    // does throw an error because all elements are equal
    bool caught_exception = false;
    try {
        check_if_data_does_change_at_all({2.0, 2.0, 2.0, 2.0, 2.0});
    } catch(TooLittleDataError) {
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
    result_2.start_index = 3;
    result_3.start_index = 1;
    result_1.end_index = 17;
    result_2.end_index = 19;
    result_3.end_index = 26;
    result_1.velocity_found = 122.451;
    result_2.velocity_found = 118.276;
    result_3.velocity_found = 115.772;
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
    result_1.velocity_found = 1811.0857;
    result_2.velocity_found = 1811.0857;
    result_3.velocity_found = 1811.0857;
    result_5.velocity_found = 1811.0857;
    result_10.velocity_found = 1811.0857;
    expected_results.push_back(result_1);
    expected_results.push_back(result_2);
    expected_results.push_back(result_3);
    expected_results.push_back(result_5);
    expected_results.push_back(result_10);
    ASSERT_RESULTS_EG(expected_results, results);
}

TEST(test_gem_finder, find_gems__throws_TrackTooShortError) {
    // generate a track which has some data but is shorter than the minimal configured fastest_distance
    Segment track = generate_track({3}, {1.0});

    // test that the TrackTooShortError is thrown
    bool caught_exception = false;
    try {
        Results results = find_gems(track);
    } catch(TrackTooShortError) {
        caught_exception = true;
    }
    assert(caught_exception);
}

TEST(test_gem_finder, find_gems__throws_TooLittleDataError) {
    // generate a track with all the same coordinates since velocity is 0
    Segment track = generate_track({10}, {0.0});

    // test that the TooLittleDataError is thrown
    bool caught_exception = false;
    try {
        Results results = find_gems(track);
    } catch(TooLittleDataError) {
        caught_exception = true;
    }
    assert(caught_exception);
}

TEST(test_gem_finder, find_gems__throws_InconsistentDataError) {
    bool caught_exception;
    // generate a segment with inconsistent vector sizes
    Coordinates c = {{1.0, 2.0}, {2.0, 1.0}};   // size 2
    Times t = {1.2, 2.3, 4.1};                  // size 3
    Elevation e = {123.4, 567.8};               // size 2
    // this will already throw the InconsistentDataError
    caught_exception = false;
    try {
        Segment seg(c, t, e);
    } catch(InconsistentDataError) {
        caught_exception = true;
    }
    assert(caught_exception);
}