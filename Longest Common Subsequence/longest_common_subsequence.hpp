#pragma once

#include <exception>
#include <iostream>
#include <algorithm>
#include <iomanip>

/// @brief This function will create 2d array
/// @param array pointer to pointer where we want to create 2d array
/// @param row number of rows
/// @param col number of cols
/// @return 2d array
int **createArray2D(int **array, int row, int col);

/// @brief This function will clear memory allocate by array T
/// @param T array we want to delete
/// @param row number of rows in array T
void delete_array(int **T, int row);

/// @brief This function will create array of size LCS (longest common subsequence) two strings
/// @param array 2d array
/// @param str1 first string
/// @param str2 second string
/// @return array of size LCS
int **lcs(int **array, std::string str1, std::string str2);

/// @brief This function will read value of LCS (longest common subsequence) two strings
/// @param array 2d array contains with size of two strings
/// @param str1 first string
/// @param str2 second string
/// @return string contain LCS
std::string readSubsequence(int **array, std::string str1, std::string str2);

/// @brief This function will return value of NWP
/// @param array 2d array
/// @param row  number of rows
/// @param col number of cols
/// @return value of NWP
int get_longest_value(int **array, int row, int col);

/// @brief This function will print every elements in array2d
/// @param array array2d
/// @param row number of rows
/// @param col number of cols
void show_arr(int **array, int row, int col);