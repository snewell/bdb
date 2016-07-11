#ifndef BDB_H
#define BDB_H 1

#include <utility>

template <typename FALLBACK>
auto bdb(FALLBACK &&fallback)
{
    return fallback();
}

template <typename RETVAL>
RETVAL bdb_makeDefault()
{
    return RETVAL{};
}

template <>
void bdb_makeDefault<void>() { }

template <typename PRED, typename EXEC>
auto bdb(PRED &&pred, EXEC &&exec)
{
    if(pred())
    {
        return exec();
    }

    // user should add a fallback function, but creating a default
    // value is the best general case solution
    using RETVAL = decltype(exec());
    return bdb_makeDefault<RETVAL>();
}

template <typename PRED, typename EXEC, typename ...REMAINING>
auto bdb(PRED &&pred, EXEC &&exec, REMAINING && ...remaining)
{
    if(pred())
    {
        return exec();
    }
    else
    {
        return bdb(std::forward<REMAINING>(remaining)...);
    }
}

#endif
