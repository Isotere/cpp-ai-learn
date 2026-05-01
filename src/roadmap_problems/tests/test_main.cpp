#include "roadmap_problems.h"

#include <gtest/gtest.h>

TEST(roadmap_problems, PrefixSumReturnsRangeSumsOnHalfOpenRanges) {
    const std::vector<int> values{1, 2, 3, 4, 5};

    const auto range_sum = roadmap_problems::make_prefix_sum(values);

    EXPECT_EQ(range_sum(0, 5), 15);
    EXPECT_EQ(range_sum(0, 3), 6);
    EXPECT_EQ(range_sum(2, 5), 12);
    EXPECT_EQ(range_sum(1, 4), 9);
}

TEST(roadmap_problems, PrefixSumSupportsEmptyRanges) {
    const std::vector<int> values{10, 20, 30};

    const auto range_sum = roadmap_problems::make_prefix_sum(values);

    EXPECT_EQ(range_sum(0, 0), 0);
    EXPECT_EQ(range_sum(1, 1), 0);
    EXPECT_EQ(range_sum(3, 3), 0);
}

TEST(roadmap_problems, PrefixSumSupportsNegativeValues) {
    const std::vector<int> values{5, -2, 7, -10};

    const auto range_sum = roadmap_problems::make_prefix_sum(values);

    EXPECT_EQ(range_sum(0, 4), 0);
    EXPECT_EQ(range_sum(1, 3), 5);
    EXPECT_EQ(range_sum(2, 4), -3);
}

TEST(roadmap_problems, PrefixSumKeepsPreparedDataAfterInputChanges) {
    std::vector<int> values{1, 2, 3};

    const auto range_sum = roadmap_problems::make_prefix_sum(values);
    values[0] = 100;

    EXPECT_EQ(range_sum(0, 3), 6);
}

TEST(roadmap_problems, NumberCounterReturnsFrequencies) {
    const std::vector<int> values{1, 2, 1, 3, 2, 1};

    const auto count = roadmap_problems::make_number_counter(values);

    EXPECT_EQ(count(1), 3);
    EXPECT_EQ(count(2), 2);
    EXPECT_EQ(count(3), 1);
}

TEST(roadmap_problems, NumberCounterReturnsZeroForMissingValues) {
    const std::vector<int> values{4, 4, 5};

    const auto count = roadmap_problems::make_number_counter(values);

    EXPECT_EQ(count(1), 0);
    EXPECT_EQ(count(6), 0);
}

TEST(roadmap_problems, NumberCounterSupportsNegativeValues) {
    const std::vector<int> values{-1, 0, -1, -2, -2, -2};

    const auto count = roadmap_problems::make_number_counter(values);

    EXPECT_EQ(count(-1), 2);
    EXPECT_EQ(count(0), 1);
    EXPECT_EQ(count(-2), 3);
}

TEST(roadmap_problems, NumberCounterSupportsEmptyInput) {
    const std::vector<int> values{};

    const auto count = roadmap_problems::make_number_counter(values);

    EXPECT_EQ(count(0), 0);
    EXPECT_EQ(count(42), 0);
}

TEST(roadmap_problems, NumberCounterKeepsPreparedDataAfterInputChanges) {
    std::vector<int> values{7, 8, 7};

    const auto count = roadmap_problems::make_number_counter(values);
    values[0] = 8;

    EXPECT_EQ(count(7), 2);
    EXPECT_EQ(count(8), 1);
}
