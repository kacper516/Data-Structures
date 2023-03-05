#include "LibError.cpp"
#include "LibFiles.cpp"
#include "LibArray.cpp"
#include "ClassItem.cpp"
#include "LibBackpack.cpp"

int main()
{
	try
	{
		// hardcoded filename
		std::string file_name = "input.txt";
		std::string line;

		std::ifstream file;

		int **backpack_array;
		int **backpack_index_array;

		std::vector<std::string> item_packed;

		f_open_file_read(file_name, file);
		int max_weight = 0, num_items = 0;

		// 1 line is maximum weight
		file >> max_weight;
		std::getline(file, line);
		while (!file.eof())
		{
			// get next lines
			std::getline(file, line);
			num_items++;
		}
		file.close();

		// declaration of memory for objects class item +1, because we start to index item from 1 not from 0
		ClassItem *items = new ClassItem[num_items + 1];
		backpack_array = f_cr_array2d(max_weight, num_items);
		backpack_index_array = f_cr_array2d(max_weight, num_items);

		f_create_backpack(backpack_array, backpack_index_array, file_name, items, num_items, max_weight);
		item_packed = f_items_packed(items, backpack_index_array, num_items, max_weight);
		f_save_to_file(backpack_array, backpack_index_array, num_items, max_weight, item_packed);
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
		exit(0);
	}
}