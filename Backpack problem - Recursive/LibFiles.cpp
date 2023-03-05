#include "LibFiles.hpp"

std::string f_check_if_txt(std::string name)
{
	// if name of file is less or equal to 4 there is 100% no ".txt" extension
	if (name.length() <= 4)
	{
		name += '.';
		name += 't';
		name += 'x';
		name += 't';
	}
	if (name[name.length() - 1] != 't' && name[name.length() - 2] != 'x' && name[name.length() - 3] != 't' && name[name.length() - 4] != '.')
	{
		name += '.';
		name += 't';
		name += 'x';
		name += 't';
	}
	return name;
}

void f_open_file_write(std::string file_name, std::ofstream &file)
{
	file.open(file_name, std::ios::out);
	if (!file.is_open())
		throw EXCEPTION_ERROR::Open_file;
}

void f_open_file_read(std::string file_name, std::ifstream &file)
{
	file.open(file_name, std::ios::in);
	if (!file.is_open())
		throw EXCEPTION_ERROR::Open_file;
}

void f_save_to_file(int **array_backpack, int **array_backpack_index, int num_elements, int max_weight, std::vector<std::string> items_packed)
{
	try
	{
		std::string output_name;
		std::ofstream file;
		std::cout << "Tell us name of output file: ";
		std::cin >> output_name;
		output_name = f_check_if_txt(output_name);
		f_open_file_write(output_name, file);
		file << "Array for best packed items: " << std::endl;
		for (int i = 1; i <= num_elements; i++)
		{
			for (int j = 1; j <= max_weight; j++)
			{
				file << array_backpack[i][j] << " ";
			}
			file << std::endl;
		}
		file << std::endl;
		file << "Array for index of items we put in our last move: " << std::endl;
		for (int i = 1; i <= num_elements; i++)
		{
			for (int j = 1; j <= max_weight; j++)
			{
				file << array_backpack_index[i][j] << " ";
			}
			file << std::endl;
		}
		file << std::endl;
		file << "Items we put into backpack for best packed items is: ";
		for (int i = 0; i < items_packed.size(); i++)
		{
			file << items_packed[i];

			// The condition as the last item will be that it does not add a comma after it
			if (i < items_packed.size() - 1)
				file << ", ";
		}
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
	}
}