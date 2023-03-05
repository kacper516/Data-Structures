#pragma once
#include<iostream>

enum EXCEPTION_ERROR {
	Open_file,
	Create_array,
	Num_edges,
	Read_file
};

/// @brief This function will print error in terminal if error will exist
/// @param error name of error while running
void f_see_error(EXCEPTION_ERROR error);