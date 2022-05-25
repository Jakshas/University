#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
vector<T> pow2(vector<T> const& input)
{
    // TODO:      This function should return input elements raised to the power of two.
    vector<T> output;
    for_each(input.begin(), input.end(),[&output](T var){output.push_back(var*var) ;});
    return output;
}

TEST(Pow2Test, Test)
{
    vector<long> input =    {2, 5,  10,  15,  20,  25,  30,  45,   100};
    vector<long> expected = {4, 25, 100, 225, 400, 625, 900, 2025, 10000};
    auto actual = pow2(input);

    ASSERT_EQ(expected, actual);
}

TEST(Pow2Test, TestDouble)
{
    vector<double> input =    {2.5, 8.2, 10.0};
    vector<double> expected = {6.25, 67.24, 100};
    auto actual = pow2(input);

    ASSERT_EQ(expected, actual);
}

int main(int ac, char ** av)
{
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

