extern "C" {
#include "utils.h"
}

#include <gtest/gtest.h>

TEST(JourneyDateTest, AcceptsValidDates) {
    EXPECT_EQ(1, isValidJourneyDate("25:10:2026"));
    EXPECT_EQ(1, isValidJourneyDate("29:02:2024"));
    EXPECT_EQ(1, isValidJourneyDate("31:12:9999"));
}

TEST(JourneyDateTest, RejectsInvalidDates) {
    EXPECT_EQ(0, isValidJourneyDate("31:04:2026"));
    EXPECT_EQ(0, isValidJourneyDate("29:02:2023"));
    EXPECT_EQ(0, isValidJourneyDate("00:12:2026"));
    EXPECT_EQ(0, isValidJourneyDate("15:13:2026"));
}

TEST(JourneyDateTest, RejectsMalformedDates) {
    EXPECT_EQ(0, isValidJourneyDate(nullptr));
    EXPECT_EQ(0, isValidJourneyDate(""));
    EXPECT_EQ(0, isValidJourneyDate("2026-10-25"));
    EXPECT_EQ(0, isValidJourneyDate("1A:10:2026"));
    EXPECT_EQ(0, isValidJourneyDate("25:10:1899"));
}
