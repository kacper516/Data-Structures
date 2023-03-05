#pragma once 

#include"ClassItem.hpp"
#include"LibError.hpp"
#include"LibArray.hpp"
#include"LibFiles.hpp"

#include<string>
#include<vector>

/// @brief This function will fill array with backpack method
/// @param array2d addres to array we will pack in
/// @param array2d_items array with index of specific items
/// @param file_name name of file
/// @param items objects of class item
/// @param num_items number of items (rows -1)
/// @param max_weight maximum weight backpack (cols -1)
/// @return addres to array fill with the best packed
int** f_create_backpack(int** array2d, int** array2d_items, std::string file_name, ClassItem* items, int num_items, int max_weight);

/// @brief This function will check which items were packed in the best packed
/// @param items objects of class item
/// @param array2d_items array fill with index of items
/// @param num_items number of items (rows -1)
/// @param max_weight maximum weight backpack (cols -1)
/// @return vector, which contains information about packed items
std::vector<std::string>f_items_packed(ClassItem* items, int** array2d_items, int num_items, int max_weight);