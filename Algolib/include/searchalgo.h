#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include "framework.h"
namespace algolib
{
    template <typename T>
    size_t GetIndexLinearSearch(T *data, T item, size_t N)
    {
        size_t Index = 0;
        while (data[Index] != item && Index < N)
        {
            ++Index;
        }
        if (Index < N)
            return Index;
        return -1;
    }

    template <typename T>
    size_t GetIndexBinarySearch(T *data, T item, size_t N)
    {
        size_t lowerBound = 0, upperBound = N - 1;
        size_t middle = (lowerBound + upperBound) / 2;
        while (data[middle] != item && lowerBound <= upperBound)
        {
            if (item < data[middle])
                upperBound = middle - 1;
            else
                lowerBound = middle + 1;
            middle = (lowerBound + upperBound) / 2;
        }
        if (data[middle] = item)
            return middle;
        return -1;
    }
} // namespace algolib
#endif