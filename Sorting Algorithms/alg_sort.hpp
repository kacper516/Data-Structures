#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

/// @brief This function will use selection sort to sort given array
/// @param arr array with elements
/// @param n number of elements in arr
void selection_sort(int *arr, int n);

/// @brief This function will use insertion sort to sort given array
/// @param arr array with elements
/// @param n number of elements in arr
void insertion_sort(int *arr, int n);

/// @brief This function will use bubble sort to sort given array
/// @param arr array with elements
/// @param n number of elements in arr
void bubble_sort(int *arr, int n);

/// @brief This function will print every element in arr
/// @param arr array
/// @param n number of elements in array
void print_arr(int *arr, int n);

/// @brief This function will use quick sort to sort given array
/// @param arr array with elements
/// @param low low index of array
/// @param high last index in array
void quick_sort(int *arr, int low, int high);

/// @brief This function will search for pivot for quick sort
/// @param arr array with elements
/// @param low low index
/// @param high high index
/// @return index of pivot
int partition(int *arr, int low, int high);

/// @brief This function will use counting sort to sort given array
/// @param arr array with elements
/// @param n number of elements in array
void counting_sort(int *arr, int n);

/// @brief This function will search for max value in array
/// @param arr array with elements
/// @param n number of elements
/// @return maximum value in array
int max_value(int *arr, int n);

/// @brief This function will search for min value in array
/// @param arr array with elements
/// @param n number of elements
/// @return minimum value in array
int min_value(int *arr, int n);

/// @brief This function will build max heap, it's helping function for heap sort
/// @param arr array with elements
/// @param n number of elements in array
void build_maxheap(int *arr, int n);

/// @brief This function will make heapify to rebuild the heap (make max heap)
/// @param arr array with elements
/// @param n number of elements in array
/// @param i largest element
void heapify(int *arr, int n, int i);

/// @brief This function will use heap sort to sort given array
/// @param arr array with elements
/// @param n number of elements in array
void heap_sort(int *arr, int n);