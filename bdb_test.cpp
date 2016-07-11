#include <gtest/gtest.h>

#include "bdb.h"

TEST(BDB, test_miss)
{
    auto x = 0;
    auto y = 0;

    auto hit = bdb([x, y] () {
                    return (x < y);
                }, [] () {
                    return true;
                });

    ASSERT_EQ(false, hit);
}

TEST(BDB, test_hit)
{
    auto x = 0;
    auto y = 0;

    auto hit = bdb([x, y] () {
                    return (x == y);
                }, [] () {
                    return true;
                });

    ASSERT_EQ(true, hit);
}

TEST(BDB, test_series)
{
    auto x = 0;
    auto y = 0;

    auto hit = bdb([x, y] () {
                    return (x < y);
                }, [] () {
                    return 1;
                },
                    [x, y] () {
                    return (x == y);
                }, [] () {
                    return 2;
                },
                    [x, y] () {
                    return (x > y);
                }, [] () {
                    return 3;
                });

    ASSERT_EQ(2, hit);
}

TEST(BDB, test_fallback)
{
    auto x = 0;
    auto y = 0;

    auto hit = bdb([x, y] () {
                    return (x < y);
                }, [] () {
                    return 1;
                },
                   [] () {
                    return 2;
                });

    ASSERT_EQ(2, hit);
}

namespace
{
    struct Foo
    {
        Foo() : _def{true} { }

        Foo(int) : _def{false} { }

        bool const _def;
    };
}

TEST(BDB, test_default)
{
    auto val = bdb([] () {
                        return false;
                    }, []() {
                        return Foo{0};
                    });

    ASSERT_EQ(true, val._def);
}

TEST(BDB, test_defaultVoid)
{
    bdb([]() {
            return false;
        }, [] () { });
}
