#pragma once

#include<iostream>

struct MainList
{
	MainList *next;
	int value;
};

struct List
{
	MainList *head = nullptr;
	/// @brief This function adds to the end of the corresponding vertex the value (number) of the vertex with which it is incident
	/// @param vertex_number pointer to incident vert
	/// @param value vertex number with which vertex_number is incidental
	void f_add_back(List *vertex_number, int value);

	/// @brief This function will show list
	void f_show_list();

	/// @brief This function will fill incident list
	/// @param vertex pointer to array fill with linked list of verts
	/// @param array2d array 2d
	/// @param max number of verts
	void f_fill_list(List *vertex, int **array2d, int max);
};

/// @brief This function will fill array with degrees of next vertices
/// @param vertex pointer to array fill with linked list of verts
/// @param array2d array 2d
/// @param max number of verts
/// @return array 1d with deegrees of vertices
int *f_fill_array_degree(List *vertex, int **array2d, int max);

/// @brief This function will show incident list and degrees of every verts
/// @param vertex pointer to list
/// @param array_degree pointer to array fill with degrees of verts
/// @param max number of verts
void f_show_info(List *vertex, int *array_degree, int max);
