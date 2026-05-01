#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "linear.h"

TEST(LinearSearch, EmptyVector) {
    const std::vector<int> input{};
    EXPECT_EQ(search::linear(input, 42), -1);
}

TEST(LinearSearch, FindsFirstElement) {
    const std::vector<int> input{10, 20, 30, 40};
    EXPECT_EQ(search::linear(input, 10), 0);
}

TEST(LinearSearch, FindsMiddleElement) {
    const std::vector<int> input{10, 20, 30, 40};
    EXPECT_EQ(search::linear(input, 30), 2);
}

TEST(LinearSearch, FindsLastElement) {
    const std::vector<int> input{10, 20, 30, 40};
    EXPECT_EQ(search::linear(input, 40), 3);
}

TEST(LinearSearch, ReturnsMinusOneWhenNotFound) {
    const std::vector<int> input{10, 20, 30, 40};
    EXPECT_EQ(search::linear(input, 99), -1);
}

TEST(LinearSearch, ReturnsFirstMatchingIndexForDuplicates) {
    const std::vector<int> input{7, 3, 7, 7};
    EXPECT_EQ(search::linear(input, 7), 0);
    EXPECT_EQ(search::linear(input, 3), 1);
}

TEST(LinearSearch, SupportsStrings) {
    const std::vector<std::string> input{"alpha", "beta", "gamma"};
    EXPECT_EQ(search::linear(input, std::string{"gamma"}), 2);
    EXPECT_EQ(search::linear(input, std::string{"delta"}), -1);
}

TEST(LinearSearch, KeepsOriginalInputUnchanged) {
    const std::vector<int> input{3, 1, 2};

    EXPECT_EQ(search::linear(input, 1), 1);
    EXPECT_EQ(input, (std::vector<int>{3, 1, 2}));
}
