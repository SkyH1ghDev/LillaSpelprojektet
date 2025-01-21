#include <lib.hpp>

#include <gtest/gtest.h>

TEST(LibTest, MeaningOfLife)
{
    ASSERT_EQ(DummyLibNamespace::libFunc(), 42);
}