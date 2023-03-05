#pragma once

#include "LibError.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/// @brief This function will create 2d array
/// @param max_weight maximum weight of backpack (number of columns)
/// @param num_examples number of items (number of rows)
/// @return addres to array 2d
int **f_cr_array2d(int max_weight, int num_examples);

/// @brief This function will create array 1d
/// @param num_elements number of elements
/// @return address to array
int *f_cr_array(int num_elements);

/// @brief This function will free memory allocated by array 2d
/// @param array2d address to array we want to delete
/// @param row number of rows
void f_delete_array2d(int **array2d, int row);