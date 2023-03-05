#pragma once

#include <iostream>

enum EXCEPTION_ERROR
{
	Valid_variables,
	Create_array,
	Open_file
};

/// @brief This function will print error in terminal if error will exist
/// @param error name of error while running
void f_see_error(EXCEPTION_ERROR error);