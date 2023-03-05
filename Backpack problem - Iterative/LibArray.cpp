#include "LibArray.hpp"

int **f_cr_array2d(int max_weight, int num_examples)
{
	try
	{
		// to starts iteration of first index not 0
		int col = max_weight + 1;
		int row = num_examples + 1;
		int **array2d = new int *[row];
		for (int i = 0; i < row; i++)
		{
			array2d[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				array2d[i][j] = 0; // fill with 0
			}
		}
		return array2d;
	}
	catch (const std::exception &)
	{
		throw EXCEPTION_ERROR::Create_array;
	}
}

int *f_cr_array(int num_elements)
{
	try
	{
		int *n_array = new int[num_elements]{};
	}
	catch (const std::exception &)
	{
		throw EXCEPTION_ERROR::Create_array;
	}
}

void f_delete_array2d(int **array2d, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] array2d[i];
	}
	delete[] array2d;
}