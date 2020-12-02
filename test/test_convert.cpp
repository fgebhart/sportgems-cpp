#include "../include/convert.h"
#include "gtest/gtest.h"


TEST(test_convert, string_to_seconds_convert) {
    std::wstring date_time;
    int expected, result;
    
    // test valid string
    date_time = L"2014-07-25T20:17:22Z";
    expected = 1406319442;
    result = get_epoch_ime(date_time);
    EXPECT_EQ(expected, result);
}
