#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "easy.h"

namespace {
// Edge: empty vector
const auto EMPTY_ARR = std::vector<long long>{};
// Regular vector
const auto REGULAR_ARR_POS = std::vector<long long>{3, 2, 1, 12, 5, 1, 6};
const auto REGULAR_ARR_NEG = std::vector<long long>{-3, -2, -1, -12, -5, -1, -6};
const auto REGULAR_ARR_COM = std::vector<long long>{3, 2, -1, -12, 5, -1, 6};

TEST(EasySumArray, HandlesBasicCases) {
    EXPECT_EQ(sum_array(EMPTY_ARR), 0);
    EXPECT_EQ(sum_array(REGULAR_ARR_POS), 30);
    EXPECT_EQ(sum_array(REGULAR_ARR_NEG), -30);
    EXPECT_EQ(sum_array(REGULAR_ARR_COM), 2);
}

TEST(MaxArray, DiesOnEmptyArray) { ASSERT_DEATH(max_array(EMPTY_ARR), ""); }

TEST(MaxArray, ReturnsIndexAndValue) {
    EXPECT_EQ(max_array(REGULAR_ARR_POS), std::make_tuple(3UZ, 12LL));
    EXPECT_EQ(max_array(REGULAR_ARR_NEG), std::make_tuple(2UZ, -1LL));
    EXPECT_EQ(max_array(REGULAR_ARR_COM), std::make_tuple(6UZ, 6LL));
}

TEST(CountArray, CountsBasicCases) {
    const auto COUNTS = count_array(REGULAR_ARR_COM);

    ASSERT_EQ(COUNTS.size(), 6);
    EXPECT_EQ(COUNTS.at(-1), 2);
    EXPECT_EQ(COUNTS.at(3), 1);
    EXPECT_EQ(COUNTS.at(6), 1);
}
}  // namespace