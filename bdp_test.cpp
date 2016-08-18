#include <gtest/gtest.h>

#include <sstream>

#include "bdp.h"

auto triple(int val)
{
    return val * 3;
}

auto square(int val)
{
    return val * val;
}

auto div2(int val)
{
    return val / 2;
}

auto toString(int val)
{
    std::ostringstream os;
    os << val;
    return os.str();
}

TEST(BDP, test_short)
{
    auto const ret = bdp(3, triple);
    ASSERT_EQ(9, ret);
}

TEST(BDP, test_long)
{
    auto const ret = bdp(2, triple, square, div2);
    ASSERT_EQ(18, ret);
}

TEST(BDP, type_change)
{
    auto const ret = bdp(2, square, toString);
    ASSERT_EQ("4", ret);
}
