#pragma once

#include "LibError.hpp"
#include "LibFiles.hpp"
#include "LibGenerator.hpp"

/// @brief This function will generate numbers, which solves a linear equation by the congruence method
/// @param gen_array array where we want to save new values
/// @param size_array size of array
/// @param modulo range
/// @return addres to array
int *f_save_to_array(int *gen_array, int size_array, int modulo);

/// @brief This function will reverse X array and save his element to new array
/// @param x_array address to array x
/// @param y_array address to array y
/// @param size_array size of array
/// @return address to new array
int *f_reverse_array(int *x_array, int *&y_array, int size_array);

/// @brief This function will use random numbers with additive congruence method
/// @param y_array address to y array
/// @param size_array size of array
/// @param modulo range
/// @param pair_array array fill with pairs i and j
/// @return addres to new array
int *f_addictive_gen(int *&y_array, int size_array, int modulo, int *pair_array);