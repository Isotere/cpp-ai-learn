#include <gtest/gtest.h>

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

#include "insertion_sort.h"

namespace {

struct StableItem {
    int key;
    int original_index;

    auto operator<=>(const StableItem& other) const { return key <=> other.key; }
    bool operator==(const StableItem& other) const {
        return key == other.key && original_index == other.original_index;
    }
};

}  // namespace

TEST(InsertionSort, EmptyVector) {
    const std::vector<int> input{};
    EXPECT_EQ(sorting::insertion(input), std::vector<int>{});
}

TEST(InsertionSort, SingleElement) {
    const std::vector<int> input{42};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{42}));
}

TEST(InsertionSort, AlreadySorted) {
    const std::vector<int> input{1, 2, 3, 4, 5};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(InsertionSort, ReverseSorted) {
    const std::vector<int> input{5, 4, 3, 2, 1};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(InsertionSort, RandomOrder) {
    const std::vector<int> input{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}));
}

TEST(InsertionSort, AllEqual) {
    const std::vector<int> input{7, 7, 7, 7};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{7, 7, 7, 7}));
}

TEST(InsertionSort, NegativeNumbers) {
    const std::vector<int> input{-3, 5, -1, 0, -10, 2};
    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{-10, -3, -1, 0, 2, 5}));
}

TEST(InsertionSort, Doubles) {
    const std::vector<double> input{3.14, 1.41, 2.71, 0.57};
    EXPECT_EQ(sorting::insertion(input), (std::vector<double>{0.57, 1.41, 2.71, 3.14}));
}

TEST(InsertionSort, Strings) {
    const std::vector<std::string> input{"banana", "apple", "cherry"};
    EXPECT_EQ(sorting::insertion(input), (std::vector<std::string>{"apple", "banana", "cherry"}));
}

TEST(InsertionSort, KeepsOriginalInputUnchanged) {
    const std::vector<int> input{3, 1, 2};

    EXPECT_EQ(sorting::insertion(input), (std::vector<int>{1, 2, 3}));
    EXPECT_EQ(input, (std::vector<int>{3, 1, 2}));
}

TEST(InsertionSort, HandlesIntLimits) {
    const std::vector<int> input{0, std::numeric_limits<int>::max(), -1, std::numeric_limits<int>::min()};
    EXPECT_EQ(sorting::insertion(input),
              (std::vector<int>{std::numeric_limits<int>::min(), -1, 0, std::numeric_limits<int>::max()}));
}

TEST(InsertionSort, MatchesStdSortOnDeterministicRandomData) {
    std::vector<int> input(256);
    std::ranges::generate(input, [value = 17]() mutable {
        value = ((value * 73) + 41) % 997;
        return value - 500;
    });

    auto expected = input;
    std::ranges::sort(expected);

    EXPECT_EQ(sorting::insertion(input), expected);
}

TEST(InsertionSort, IsStableForEquivalentKeys) {
    const std::vector<StableItem> input{
        {.key = 2, .original_index = 0},
        {.key = 1, .original_index = 1},
        {.key = 2, .original_index = 2},
        {.key = 1, .original_index = 3},
        {.key = 2, .original_index = 4}
    };

    EXPECT_EQ(sorting::insertion(input), (std::vector<StableItem>{
                                             {.key = 1, .original_index = 1},
                                             {.key = 1, .original_index = 3},
                                             {.key = 2, .original_index = 0},
                                             {.key = 2, .original_index = 2},
                                             {.key = 2, .original_index = 4}
    }));
}
