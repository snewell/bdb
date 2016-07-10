#ifndef BDB_H
#define BDB_H 1

#include <utility>

template <typename FALLBACK>
void bdb(FALLBACK &&fallback)
{
    fallback();
}

template <typename PRED, typename EXEC>
void bdb(PRED &&pred, EXEC &&exec)
{
    if(pred())
    {
        exec();
    }
}

template <typename PRED, typename EXEC, typename ...REMAINING>
void bdb(PRED &&pred, EXEC &&exec, REMAINING && ...remaining)
{
    if(pred())
    {
        exec();
    }
    else
    {
        bdb(std::forward<REMAINING>(remaining)...);
    }
}

#endif
