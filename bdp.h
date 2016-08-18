#ifndef BDP_H
#define BDP_H 1

#include <utility>

template <typename T, typename FN>
auto bdp(T && val, FN && fn)
{
    return fn(std::forward<T>(val));
}

template <typename T, typename FN, typename ...FNs>
auto bdp(T && val, FN && fn, FNs && ...fns)
{
    return bdp(fn(std::forward<T>(val)), std::forward<FNs>(fns)...);
}

#endif
