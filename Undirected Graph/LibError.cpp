#include "LibError.hpp"

void f_see_error(EXCEPTION_ERROR error)
{
	switch (error)
	{
	case Open_file:
		std::cerr << "Error while opening file.";
		break;
	case Create_array:
		std::cerr << "Error while creating array.";
		break;
	case Num_edges:
		std::cerr << "Wrong number of edges.";
		break;
	case Read_file:
		std::cerr << "Error while reading from file.";
		break;
	default:
		std::cerr << "Unexpected error.";
		break;
	}
}