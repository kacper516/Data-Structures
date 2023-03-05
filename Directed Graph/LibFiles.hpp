#pragma once

#include"LibError.hpp"

#include<string>
#include<fstream>

/// @brief This function will check if name given by user has got ".txt" extension
/// @param name name of file given by user
/// @return string with ".txt" extension (if not have before)
std::string f_check_if_txt(std::string name);

/// @brief This function will open file
/// @param file_name name of file we want to open
/// @param file file we want to operate on
void f_open_file(std::string file_name, std::ifstream &file);

/// @brief This function will check number of edges and check if it's possible value
/// @param file file from we want to read
/// @return number of edges
float f_check_num_edges(std::ifstream &file);

/// @brief This function will check maximum number of verts
/// @param num_edges number of edges
/// @param file file we read from
/// @return maximum value of vert
float f_check_max(int num_edges, std::ifstream &file);
