#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include "framework.h"

template <typename T>
size_t GetIndexLinearSearch(T* data, T item, size_t N)
{
    sizet_t Index = 0;
    while(data[Index] != item && Index < N)
    {
        ++Index;
    }
    if (Index <N)
        return Index;
    return -1;
}

#endif