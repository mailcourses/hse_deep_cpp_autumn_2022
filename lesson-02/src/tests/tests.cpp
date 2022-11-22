#include <iostream>
#include <gtest/gtest.h>

#include "utils.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
};

// Тест успешно пройдёт.
TEST(TestUtils, test_avg)
{
    int arr[5] = {1,2,3,4,5};
    double actual = avg(arr, 5);
    ASSERT_EQ( actual, 3.f );
}

// Тест поломан.
TEST(TestUtils, test_avg_failed)
{
    int arr[5] = {1,2,3,4,5};
    double actual = avg(arr, 5);
    ASSERT_EQ( actual, 2.f );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
