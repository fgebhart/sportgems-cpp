#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <math.h>
#include <limits>
#include <iostream>

#include "../include/types.h"
#include "gtest/gtest.h"


void ASSERT_TIMES_VEC_EQ(Times const &expected_t, Times const result_t) {
    ASSERT_EQ(expected_t.size(), result_t.size()) << "times vectors are of unequal length";

    for (int i = 0; i < result_t.size(); ++i) {
        EXPECT_EQ(expected_t[i], result_t[i]);
    }
}

void ASSERT_VEC_OF_FLOATS_EQ(Elevation const &expected_e, Elevation const result_e) {
    ASSERT_EQ(expected_e.size(), result_e.size()) << "elevation vectors are of unequal length";

    for (int i = 0; i < result_e.size(); ++i) {
        ASSERT_NEAR(expected_e[i], result_e[i], 0.0001);
    }
}

void ASSERT_COORDINATES_VEC_EQ(Coordinates const &expected_c, Coordinates const &result_c) {
    ASSERT_EQ(expected_c.size(), result_c.size()) << "coordinates are of unequal length";

    for (int i = 0; i < result_c.size(); ++i) {
        ASSERT_NEAR(expected_c[i].first, result_c[i].first, 0.0001);
        ASSERT_NEAR(expected_c[i].second, result_c[i].second, 0.0001);
    }
}

void ASSERT_SEGMENT_EQ(Segment const &expected_track, Segment const &result_track) {
    ASSERT_COORDINATES_VEC_EQ(expected_track.coordinates, result_track.coordinates);
    ASSERT_TIMES_VEC_EQ(expected_track.times, result_track.times);
    ASSERT_VEC_OF_FLOATS_EQ(expected_track.elevation, result_track.elevation);
}

#endif
