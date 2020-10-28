#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include "framework.h"
namespace algolib
{
    template <typename T>
    size_t GetIndexLinearSearch(T *data, T item, size_t N, bool naturalNum = false)
    {
        size_t Index = 0;
        while (data[Index] != item && Index < N)
        {
            ++Index;
        }
        if (Index < N)
        {
            if (naturalNum)
                ++Index;
            return Index;
        }
        return 0;
    }
} // namespace algolib
#endif