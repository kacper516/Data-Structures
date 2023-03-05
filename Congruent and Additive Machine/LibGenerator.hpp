#pragma once

#include "LibError.hpp"

#include <vector>
#include <iostream>
#include <cmath>

/// @brief This function will count prime factors of number then save it to vector
/// @param num number we want to break down into prime factors
/// @return vector fill with prime factors of number
std::vector<int> f_prime_factors(int num);

/// @brief This function will show prime factors of number
/// @param vector vector fill with prime factor numbers
void f_show_pf(std::vector<int> vector);

/// @brief This function will search for increase which will be relatively first to m
/// @param num_range range
/// @return number which will be relatively first to m
int f_check_increase(int num_range);

/// @brief This function will count biggest NWD of 2 numbers
/// @param first_numb first number
/// @param second_numb second number (range of numbers we want to draw from)
/// @return biggest NWD of 2 numbers
int f_NWD(int first_numb, int second_numb);

/// @brief This function will search for multiplier which will meet the assumptions
/// @param num_range range
/// @return value of multiplier
int f_check_multiplier(int num_range);

/// @brief This function will check if multiplier-1 is a multiple of every prime p that is divisible by m
/// @param num_range range
/// @param multiplier multiplier
/// @return true if first condition is fulfilled, else false
bool f_first_condition(int num_range, int multiplier);

/// @brief This function will check if multiplier-1 is a a multiple of 4, and num_range is also multiple of 4
/// @param num_range range
/// @param multiplier multiplier
/// @return true if second condition is fulfilled, else false
bool f_second_condition(int num_range, int multiplier);
