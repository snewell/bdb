#include <gtest/gtest.h>

#include "bdb.h"

TEST(BDB, test_miss)
{
    auto x = 0;
    auto y = 0;

    auto hit = false;
    bdb([x, y] () {
        return (x < y);
    }, [&hit] () {
        hit = true;
    });

    ASSERT_EQ(false, hit);
}

TEST(BDB, test_hit)
{
    auto x = 0;
    auto y = 0;

    auto hit = false;
    bdb([x, y] () {
        return (x == y);
    }, [&hit] () {
        hit = true;
    });

    ASSERT_EQ(true, hit);
}

TEST(BDB, test_series)
{
    auto x = 0;
    auto y = 0;

    auto hit = 0;
    bdb([x, y] () {
        return (x < y);
    }, [&hit] () {
        hit = 1;
    }, [x, y] () {
        return (x == y);
    }, [&hit] () {
        ASSERT_EQ(0, hit);
        hit = 2;
    }, [x, y] () {
        return (x > y);
    }, [&hit] () {
        hit = 3;
    });

    ASSERT_EQ(2, hit);
}

TEST(BDB, test_fallback)
{
    auto x = 0;
    auto y = 0;

    auto hit = 0;
    bdb([x, y] () {
        return (x < y);
    }, [&hit] () {
        hit = 1;
    }, [&hit] () {
        hit = 2;
    });

    ASSERT_EQ(2, hit);
}
