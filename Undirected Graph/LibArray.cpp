#include "LibArray.hpp"

int **f_cr_square_array2d(float max)
{
	try
	{
		int row = max;
		int col = max;
		int **array2d = new int *[row];
		for (int i = 0; i < row; i++)
		{
			array2d[i] = new int[row];
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
		exit(0);
	}
}

void f_cr_adjacency_matrix(int **array2d, std::ifstream &file)
{
	int first_vertex{}, second_vertex{};
	file.seekg(1, std::ios::beg);
	while (!file.eof())
	{
		// read verts from file
		file >> first_vertex;
		file >> second_vertex;

		// because index of array in c++ starts with 0 not 1
		first_vertex--;
		second_vertex--;

		// it's undirected graph
		array2d[first_vertex][second_vertex] = 1;
		array2d[second_vertex][first_vertex] = 1;
	}
}

void f_show_adjacency_matrix(int **array2d, float max)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			std::cout << array2d[i][j];
		}
		std::cout << std::endl;
	}
}

int **f_cr_array2d(float max, float edges)
{
	try
	{
		int row = edges;
		int col = max;
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
		exit(0);
	}
}

void f_fill_incident_matrix_array(int **square_array2d, int **array2d, float max)
{
	int row = 0;
	for (int i = 0; i < max - 1; i++)
	{
		for (int col = i + 1; col < max; col++)
		{
			if (square_array2d[i][col] == 1)
			{
				array2d[row][i] = 1;
				array2d[row][col] = -1;
				row++;
			}
			else if (square_array2d[i][col] == -1)
			{
				array2d[row][i] = -1;
				array2d[row][col] = 1;
				row++;
			}
		}
	}
}

void f_show_incident_matrix_array(int **array2d, float edges, float max)
{
	for (int i = 0; i < edges; i++)
	{
		for (int j = 0; j < max; j++)
		{
			std::cout << array2d[i][j];
		}
		std::cout << std::endl;
	}
}

void f_delete_array2d(int **array2d, float row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] array2d[i];
	}
	delete[] array2d;
}

void f_neighbourhood(int **array_neigbourhood, int **array2d, float edges, float max)
{
	// -1 because the value is unreachable in array index
	int start_v = -1;
	int end_v = -1;

	for (int i = 0; i < edges; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (array2d[i][j] == 1)
				start_v = j; // the column corresponds to the vertices
			if (array2d[i][j] == -1)
				end_v = j; // the column corresponds to the vertices
			if (start_v != -1 && end_v != -1)
				array_neigbourhood[start_v][end_v] = 1;
		}
		start_v = -1;
		end_v = -1;
	}

	for (int i = 0; i < max; i++)
	{
		std::cout << "Neighbourhood for v=" << i + 1 << " ";
		for (int j = 0; j < max; j++)
		{
			// +1 because we count verts from 1 not 0
			if (array_neigbourhood[i][j] == 1)
			{
				std::cout << j + 1 << " ";
			}
		}
		std::cout << std::endl;
	}
}