#pragma once

#include"LibError.hpp"

#include<fstream>
#include<string>
#include<vector>


/// @brief This function will check if name given by user has got ".txt" extension
/// @param name name of file given by user
/// @return string with ".txt" extension (if not have before)
std::string f_check_if_txt(std::string name);

/// @brief This function will open file to write in
/// @param file_name file name we want to open
/// @param file variable of file we want to operate on
void f_open_file_write(std::string file_name, std::ofstream &file);

/// @brief This function will open file to read from
/// @param file_name file name we want to open
/// @param file variable of file we want to operate on
void f_open_file_read(std::string file_name, std::ifstream &file);

/// @brief This function will save to  file specific information
/// @param array_backpack addres to array with best packed
/// @param array_backpack_index address to array fill with index of best packed items
/// @param num_elements number of elements (row - 1)
/// @param max_weight maximum weight of backpack (cols -1)
/// @param items_packed vector with best packed items
void f_save_to_file(int **array_backpack, int **array_backpack_index, int num_elements, int max_weight, std::vector<std::string> items_packed);