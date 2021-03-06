#pragma once

#include <vector>

/*
 * Consider an a sequence of numbers
 * i, i+1, i+2, ... i+n
 * This sequence it rotated such that it is now
 * i+n-m+1, ..., i+n, i, i+2, i+2, ..., i+n-m
 * 0, ..., m, ..., n
 * 
 * These functions find the pivot index (m) at which rotation occurs
 */
// eg 3 4 5 6 1 2

inline int findPivotSequentialSearch(std::vector<int> arr)
{
    const int sz = arr.size();
    if(arr[sz-1] > arr[0])
        return 0;
    for(int i=0 ; i<arr.size()-2 ; ++i)
    {
        if(arr[i] > arr[i+1])
            return i;
    }
    // never reached
    return -1;
};

inline int findPivotBinarySearchImpl(std::vector<int> arr, int minIdx, int maxIdx)
{
    int midIdx = (minIdx + maxIdx)/2;
    // found it (6) ** 1
    if(arr[midIdx] > arr[midIdx+1])
        return midIdx;
    // found it 6 ** (1)
    if(arr[midIdx] < arr[midIdx-1])
        return midIdx - 1;
    // if first element of the array is less than the mid element
    // then pivot is in the higher (right) part
    if( arr[minIdx] < arr[midIdx-1] )
        return findPivotBinarySearchImpl( arr, midIdx + 1, maxIdx );
    // otherwise it is on the left
    return findPivotBinarySearchImpl( arr, minIdx, midIdx - 1 );
};

inline int findPivotBinarySearch(std::vector<int> arr)
{
    const int sz = arr.size();
    if(arr[sz-1] > arr[0])
        return 0;
    return findPivotBinarySearchImpl(arr, 0, arr.size()-1);
}
