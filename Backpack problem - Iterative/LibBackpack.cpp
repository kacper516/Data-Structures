#include "LibBackpack.hpp"

int **f_create_backpack(int **array2d, int **array2d_items, std::string file_name, ClassItem *items, int num_items, int max_weight)
{
	items[0].item_name = "";
	items[0].item_weight = 0;
	items[0].item_price = 0;
	f_save_to_class(items, file_name);

	for (int i = 1; i <= num_items; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			// if we can pack items, j is iteration of next wages
			if (j >= items[i].item_weight)
			{
				if (items[i].item_price + array2d[i][j - items[i].item_weight] > array2d[i - 1][j])
				{
					array2d[i][j] = items[i].item_price + array2d[i][j - items[i].item_weight];
					array2d_items[i][j] = i;
				}
				else
				{
					array2d[i][j] = array2d[i - 1][j];
					array2d_items[i][j] = array2d_items[i - 1][j];
				}
			}
			else
			{
				array2d[i][j] = array2d[i - 1][j];
				array2d_items[i][j] = array2d_items[i - 1][j];
			}
		}
	}
	return array2d;
}

std::vector<std::string> f_items_packed(ClassItem *items, int **array2d_items, int num_items, int max_weight)
{
	int item_index = 0;
	std::vector<std::string> items_packed;
	while (max_weight != 0)
	{
		item_index = array2d_items[num_items][max_weight];
		max_weight -= items[item_index].item_weight;
		items_packed.push_back(items[item_index].item_name);
	}
	return items_packed;
}