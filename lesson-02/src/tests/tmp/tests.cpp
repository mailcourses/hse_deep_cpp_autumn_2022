#include <iostream>
#include <gtest/gtest.h>

#include "allocator.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
};

// Тест успешно пройдёт.
TEST(TestUtils, test_avg)
{
    Allocator al;
    al.makeAllocator( 10 );
    // У нас есть 10 байт свободных,
    // 5 отдадим.
    {
        char *res = al.alloc( 5 );
        ASSERT_TRUE( res != nullptr );
    }

    // У нас есть 5 (10 - 5) байт свободных,
    // 5 отдадим.
    {
        char *res = al.alloc( 5 );
        ASSERT_TRUE( res != nullptr );
    }

    // У нас есть 0 (10 - 0 - 0) байт свободных,
    // nullptr отдадим.
    {
        char *res = al.alloc( 1 );
        ASSERT_EQ( res, nullptr );
    }

    al.reset();
    // 10 байт доступно, запросим 1.
    {
        char *res = al.alloc( 1 );
        ASSERT_TRUE( res != nullptr );
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
