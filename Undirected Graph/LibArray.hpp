#pragma once

#include "LibError.hpp"
#include "LibFiles.hpp"

#include <string>
#include <iostream>
#include <fstream>

/// @brief This function will create 2d array
/// @param max maximum value in verts (it will be number of rows and cols)
/// @return addres to new array
int **f_cr_square_array2d(float max);

/// @brief This function will create adjacency matrix
/// @param array2d array 2d
/// @param file file which we will read from
void f_cr_adjacency_matrix(int **array2d, std::ifstream &file);

/// @brief This function will show adjacency matrix
/// @param array2d array 2d
/// @param max maximum value in verts (it will be number of rows and cols)
void f_show_adjacency_matrix(int **array2d, float max);

/// @brief This function will create 2d array fill with edges
/// @param max maximum value in verts (it will be number of rows and cols)
/// @param edges number of edges (number of rows)
/// @return address to array 2d
int **f_cr_array2d(float max, float edges);

/// @brief This function will fill adjacency matrix with specific values (-1 or 1)
/// @param square_array2d addres of square 2d array
/// @param array2d address of adjacency matrix
/// @param max maximum value in verts (it will be number of rows and cols)
void f_fill_incident_matrix_array(int **square_array2d, int **array2d, float max);

/// @brief This function will show incident matrix array
/// @param array2d array 2d
/// @param edges number of edges
/// @param max number of verts
void f_show_incident_matrix_array(int **array2d, float edges, float max);

/// @brief This function will free memory allocate by array 2d
/// @param array2d array 2d
/// @param row number of rows
void f_delete_array2d(int **array2d, float row);

/// @brief This function will print neighbourhood of verts
/// @param array_neigbourhood array fill with verts
/// @param array2d array 2d
/// @param edges number of edges
/// @param max number of verts
void f_neighbourhood(int **array_neigbourhood, int **array2d, float edges, float max);