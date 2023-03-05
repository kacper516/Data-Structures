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

void f_open_file(std::string file_name, std::ifstream &file)
{
	file.open(file_name, std::ios::in);
	if (!file.is_open())
		throw EXCEPTION_ERROR::Open_file;
}

float f_check_num_edges(std::ifstream &file)
{
	std::string num; // number of verts
	float fl_num;
	std::getline(file, num);
	fl_num = stoi(num);
	if (fl_num - int(fl_num) != 0 || fl_num < 0)
		throw EXCEPTION_ERROR::Num_edges; // then it's not a total number
	return fl_num;
}

float f_check_max(int num_edges, std::ifstream &file)
{
	float current_max, new_max = 0, num_numbers = num_edges * 2; //*2 because it's number pairs
	for (int i = 0; i < num_numbers; i++)
	{
		file >> current_max;
		if (current_max > new_max)
			new_max = current_max;
	}
	return new_max;
}