#include "LibArray.cpp"
#include "LibFiles.cpp"
#include "LibVector.cpp"
#include "LibError.cpp"

int main()
{

	std::string file_name;
	std::ifstream file;

	// program will check if it's total value
	float num_edges, max;
	int **square_array2d;
	int **array2d;
	int **neighbourhood_array;

	std::vector<int> vector_matrix;

	try
	{
		std::cout << "Tell us name of your file: "; // name i use in this example is test
		std::cin >> file_name;
		file_name = f_check_if_txt(file_name);
		f_open_file(file_name, file);

		num_edges = f_check_num_edges(file);
		max = f_check_max(num_edges, file);
		square_array2d = f_cr_square_array2d(max);
		f_cr_adjacency_matrix(square_array2d, file);

		std::cout << std::endl;
		array2d = f_cr_array2d(max, num_edges);

		f_fill_incident_matrix_array(square_array2d, array2d, max);
		std::cout << "Array incident matrix: " << std::endl;
		f_show_incident_matrix_array(array2d, num_edges, max);

		std::cout << std::endl;
		std::cout << "Vector incident matrix: " << std::endl;
		vector_matrix = f_fill_incident_matrix_vector(vector_matrix, array2d, max, num_edges);
		f_show_incident_matrix_vector(vector_matrix, max);

		std::cout << "\n"
				  << std::endl;

		std::cout << "Neigbourhood for every vertex: " << std::endl;
		neighbourhood_array = f_cr_array2d(max, max);
		f_neighbourhood(neighbourhood_array, array2d, num_edges, max);

		// to free memory located by this arrays
		f_delete_array2d(neighbourhood_array, max);
		f_delete_array2d(square_array2d, max);
		f_delete_array2d(array2d, num_edges);
		file.close();
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
		return 0;
	}
}
