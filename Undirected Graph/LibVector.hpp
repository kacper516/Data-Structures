#pragma once

#include <vector>
#include <iostream>

/// @brief This function will fill incident matrix with specific values (-1 or 1)
/// @param vector vector of incident matrix
/// @param array2d array 2d of incident matrix (empty)
/// @param max number of verts
/// @param edges number of edges
/// @return vector fill with values
std::vector<int> f_fill_incident_matrix_vector(std::vector<int> vector, int **array2d, float max, float edges);

/// @brief This function will show incident matrix save in vector
/// @param vector vector which contains values
/// @param max number of verts of graph
void f_show_incident_matrix_vector(std::vector<int> vector, float max);