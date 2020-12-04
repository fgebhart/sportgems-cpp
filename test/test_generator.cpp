#include "../include/generator.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_generator, generate_track) {
    Generator gen(3, 2.0);
    Track result_track = gen.generate_track();

    Coordinates expected_c = {{40.001, 10}, {40.003, 10}, {40.005, 10}};
    Times expected_t = {1, 3, 5};
    Elevation expected_e = {100.001, 100.003, 100.005};
    Track expected_track(expected_c, expected_t, expected_e);

    ASSERT_TRACK_EQ(expected_track, result_track);
}
