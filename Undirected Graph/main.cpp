#include "LibArray.cpp"
#include "LibFiles.cpp"
#include "LibVector.cpp"
#include "LibError.cpp"
#include "LibList.cpp"

int main()
{
	std::string file_name;
	std::ifstream file;
	int num_edges; 		  // number of edges
	int max; 			  //number of verts
	int **square_array2d; // square array 2d
	int *arraydegree;	  // array fill with degrees
	List *vertex;		  // list of incident verts
	try
	{
		std::cout << "Tell us name of your file: "; // for this exapmle i use test.txt file

		std::cin >> file_name;
		std::cout << std::endl;

		file_name = f_check_if_txt(file_name);
		f_open_file(file_name, file);

		num_edges = f_check_num_edges(file);
		max = f_check_max(num_edges, file);

		square_array2d = f_cr_square_array2d(max);
		f_cr_adjacency_matrix(square_array2d, file);

		vertex = new List[max]; // as many lists as vertices
		vertex->f_fill_list(vertex, square_array2d, max);
		arraydegree = f_fill_array_degree(vertex, square_array2d, max);
		f_show_info(vertex, arraydegree, max);

		delete[] arraydegree;
		f_delete_array2d(square_array2d, max);
		file.close();
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
		return 0;
	}
}
