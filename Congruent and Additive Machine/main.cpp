#include "LibError.hpp"
#include "LibGenerator.hpp"
#include "LibFiles.hpp"
#include "LibArray.hpp"

int main()
{
	std::cout << "Tell me which generator you want to use" << std::endl;
	std::cout << "Pick 1 if it's LCG" << std::endl;
	std::cout << "Pick 2 if it's Addictive generator" << std::endl;
	int which_one;
	std::cout << std::endl;
	std::cin >> which_one;
	std::cout << std::endl;
	switch (which_one)
	{
	case 1:
		try
		{
			int x_max, num_numbers, num_range, first_num;
			std::string file_name;
			system("cls");
			std::cout << "Tell me how many numbers you want" << std::endl;
			std::cin >> num_numbers;
			system("cls");
			std::cout << "Tell me max vaule to generate" << std::endl;
			std::cin >> x_max;
			system("cls");
			if (x_max <= 0 or num_numbers < 0)
				throw EXCEPTION_ERROR::Valid_variables;
			num_range = x_max + 1;
			std::cout << "Tell me seed" << std::endl;
			std::cin >> first_num;
			system("cls");
			if (first_num < 0 or first_num >= num_range)
				throw EXCEPTION_ERROR::Valid_variables;
			std::cout << "Tell me name of file_output" << std::endl;
			std::cin >> file_name;
			system("cls");
			f_save_to_file_linear(num_range, num_numbers, first_num, file_name);
		}
		catch (EXCEPTION_ERROR error)
		{
			f_see_error(error);
			return 0;
		}
		break;
	case 2:
		try
		{
			int n;
			int m;
			int *pair_array;
			int *x_array;
			int *y_array;
			system("cls");

			// hardcoded name of the file where the pairs are

			std::string file_name = "pairs.txt";
			std::cout << "Tell me size of array" << std::endl;
			std::cin >> n;
			system("cls");
			std::cout << "Tell me the modulo" << std::endl;
			std::cin >> m;
			system("cls");
			if (n <= 0 or m <= 0)
				throw EXCEPTION_ERROR::Valid_variables;
			pair_array = f_search_pairs(file_name, n);
			x_array = f_save_to_array(x_array, n, m);
			y_array = f_reverse_array(x_array, y_array, n);
			y_array = f_addictive_gen(y_array, n, m, pair_array);
			f_save_to_file_addictive(y_array, n);

			delete[] y_array;
			delete[] pair_array;
			delete[] x_array;
		}
		catch (EXCEPTION_ERROR error)
		{
			f_see_error(error);
			return 0;
		}
		break;
	default:
		break;
	}
}
