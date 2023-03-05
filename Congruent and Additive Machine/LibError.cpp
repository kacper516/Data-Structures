#include "LibError.hpp"

void f_see_error(EXCEPTION_ERROR error)
{
	switch (error)
	{
	case Valid_variables:
		std::cerr << "Inconsistent variables.";
		break;
	case Create_array:
		std::cerr << "Error while creating array.";
		break;
	case Open_file:
		std::cerr << "Error while opening file.";
		break;
	default:
		std::cerr << "Uexpected error.";
		break;
	}
}