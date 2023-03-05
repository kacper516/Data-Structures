#include "LibVector.hpp"

std::vector<int> f_fill_incident_matrix_vector(std::vector<int> vector, int **array2d, float max, float edges)
{
	for (int i = 0; i < edges; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (array2d[i][j] == 1)
				vector.push_back(1);
			else if (array2d[i][j] == 0)
				vector.push_back(0);
			else if (array2d[i][j] == -1)
				vector.push_back(-1);
		}
	}
	return vector;
}

void f_show_incident_matrix_vector(std::vector<int> vector, float max)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i > 0 && i % int(max) == 0)
		{
			std::cout << std::endl; // make free spaces between 2 rows
		}
		std::cout << vector[i];
	}
}