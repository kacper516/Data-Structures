#pragma once

#include <iostream>
#include <time.h>
#include <algorithm>

/// @brief This function will use linear search to find given value (if exist!)
/// @param S pointer to an array
/// @param n number of elements in array
/// @param x number we want to find
/// @return index of x if exist in array if not it'll return -1
int linearSearch(int *S, int n, int x);

/// @brief This function will use binary search to find given value (if exist!)
/// @param S pointer to an array
/// @param n number of elements in array
/// @param x number we want to find
/// @return index of x if exist in array if not it'll return -1
int binarySearch(int *S, int n, int x);

/// @brief This function will fill given array with random values in range 0 -> n-1
/// @param S pointer to an array we want to fill
/// @param n numbers of elements we need to put in an array and also range of our range function
void init(int *S, int n);

/// @brief This function will sort given array
/// @param S pointer to an array
/// @param n number of elements in an array
void initSorted(int *S, int n);

/// @brief This function will use interpolation search to find given value (if exist!)
/// @param S pointer to an array
/// @param n number of elements in array
/// @param x number we want to find
/// @return index of x if exist in array if not it'll return -1
int interpolationSearch(int *S, int n, int x);
