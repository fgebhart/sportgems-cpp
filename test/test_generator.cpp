#include "../include/generator.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_generator, generate_single_segment) {
    Generator gen;
    Segment result_seg = gen.generate_segment(3, 2.0);

    Coordinates expected_c = {{40.002, 10}, {40.004, 10}, {40.006, 10}};
    Times expected_t = {1, 2, 3};
    Elevation expected_e = {100.02, 100.04, 100.06};
    Segment expected_seg(expected_c, expected_t, expected_e);

    ASSERT_SEGMENT_EQ(expected_seg, result_seg);
}

TEST(test_generator, generate_entire_track) {
    Segment result_track = generate_track({1, 2, 3}, {1.0, 2.0, 3.0});

    Coordinates expected_c = {{40.002, 10}, {40.004, 10}, {40.006, 10}, {40.009, 10}, {40.012, 10}, {40.015, 10}};
    Times expected_t = {2, 3, 4, 5, 6, 7};
    Elevation expected_e = {100.011, 100.031, 100.051, 100.081, 100.111, 100.141};
    Segment expected_track(expected_c, expected_t, expected_e);

    ASSERT_SEGMENT_EQ(expected_track, result_track);
}
