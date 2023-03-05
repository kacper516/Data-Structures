#pragma once

#include<vector>
#include"LibError.hpp"

/// @brief This function will use recursive to search for best pack of bacpkack
/// @param vector_weight vector with every item
/// @param vector_return vector which we can return best pack
/// @param actual_index index which we can move on the next intems of vector
/// @param max_weight max weight of backpack
/// @return true if we can find best pack of bacpkack
bool f_backpack_recursion(std::vector<int> vector_weight, std::vector<int>& vector_return, int actual_index, int max_weight);
