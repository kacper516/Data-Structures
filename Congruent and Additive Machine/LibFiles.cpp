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

void f_save_to_file_linear(int num_range, int num_numb, int first_numb, std::string file_name)
{
	file_name = f_check_if_txt(file_name);
	std::ofstream file_to_save;
	f_open_file_write(file_name, file_to_save);

	int a = f_check_multiplier(num_range);

	// at beggining it's this value of x in mathematical formula
	int x0 = first_numb;
	int c = f_check_increase(num_range);

	for (int i = 0; i < num_numb; i++)
	{
		// for the general case
		file_to_save << (a * x0 + c) % num_range << std::endl;
		x0 = (a * x0 + c) % num_range;
	}
	file_to_save.close();
}

void f_open_file_read(std::string file_name, std::ifstream &file)
{
	file.open(file_name, std::ios::in);
	if (!file.is_open())
		throw EXCEPTION_ERROR::Open_file;
}

int *f_search_pairs(std::string file_name, int size_array)
{
	int *pair_array = new int[2];

	int first_number;
	int second_number;
	int compare_result = 0;
	int compare_result_max = 0;

	std::ifstream file;

	f_open_file_read(file_name, file);
	while (file.eof() == false)
	{
		// we read pairs from file
		file >> first_number;
		file >> second_number;

		// -1 because index starts with 0
		if (second_number > size_array - 1)
			continue;
		compare_result = second_number - first_number;

		// we compare actual pairs with new pairs
		if (compare_result >= compare_result_max)
		{
			compare_result_max = compare_result;
			pair_array[0] = first_number;
			pair_array[1] = second_number;
		}
		compare_result = 0;
	}
	file.close();
	return pair_array;
}

void f_save_to_file_addictive(int *y_array, int size_array)
{
	std::string file_name;
	std::ofstream file;
	std::cout << "Tell me output name" << std::endl;
	std::cin >> file_name;
	system("cls");
	file_name = f_check_if_txt(file_name);
	f_open_file_write(file_name, file);
	for (int i = 1; i <= size_array; i++)
	{
		file << y_array[i] << std::endl;
	}
	file.close();
}