#include "../include/parser.h"
#include "test_helper.h"
#include "gtest/gtest.h"


TEST(test_parser, parse_file) {
    XMLParser parser("../test/data/tiny.gpx");
    auto result = parser.parse_file();
    Coordinates expected_c = {{49.4795, 8.4711}, {49.4796, 8.4712}, {49.4797, 8.4713}};
    Times expected_t = {1606651201, 1606651205, 1606651209};
    Elevation expected_e = {321.2, 321.3, 321.5};

    ASSERT_COORDINATES_VEC_EQ(expected_c, result.coordinates);
    ASSERT_TIMES_VEC_EQ(expected_t, result.times);
    ASSERT_ELEVATION_VEC_EQ(expected_e, result.elevation);
}

TEST(test_parser, string_to_seconds_convert) {
    std::wstring date_time;
    int expected, result;
    
    // test valid string
    date_time = L"2014-07-25T20:17:22Z";
    expected = 1406319442;
    result = get_epoch_ime(date_time);
    EXPECT_EQ(expected, result);
}
