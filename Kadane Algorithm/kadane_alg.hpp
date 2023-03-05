#pragma once

#include <iostream>

/// @brief This function create 2d array
/// @param row number of rows
/// @param col number of cols
/// @return addres to 2d array
int **create_arr(int row, int col);

/// @brief This function will create 1d array fill with elements sum of concrete rows then search for maximum sum
/// @param arr array 2d
/// @param row number of rows
/// @param col number of cols
void current_max(int **arr, int row, int col);

/// @brief This function will search for maximum submatrix
/// @param arr array 1d
/// @param col number of cols (element in array)
/// @return maximum sum of elements
int alg_kadane(int *arr, int col);

/// @brief This function will delete array 2d
/// @param arr array 2d
/// @param row number of rows
void delete_array(int **arr, int row);