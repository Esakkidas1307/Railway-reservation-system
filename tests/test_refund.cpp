extern "C" {
#include "refund.h"
}

#include <gtest/gtest.h>

TEST(RefundTest, CalculatesSeventyFivePercent) {
    EXPECT_FLOAT_EQ(75.0f, calculateRefundAmount(100.0f));
    EXPECT_FLOAT_EQ(37.5f, calculateRefundAmount(50.0f));
}

TEST(RefundTest, ZeroFareReturnsZero) {
    EXPECT_FLOAT_EQ(0.0f, calculateRefundAmount(0.0f));
}

TEST(RefundTest, NegativeFareReturnsZero) {
    EXPECT_FLOAT_EQ(0.0f, calculateRefundAmount(-100.0f));
}
