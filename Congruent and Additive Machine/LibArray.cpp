#include "LibArray.hpp"

int *f_save_to_array(int *gen_array, int size_array, int modulo)
{
	try
	{
		gen_array = new int[size_array];
	}
	catch (EXCEPTION_ERROR error)
	{
		throw EXCEPTION_ERROR::Create_array;
	}
	try
	{
		int first_num;
		std::cout << "Tell me seed" << std::endl;
		std::cin >> first_num;
		system("cls");
		if (first_num < 0)
			throw EXCEPTION_ERROR::Valid_variables;
		int a = f_check_multiplier(modulo);

		//at beggining it's this value of x in mathematical formula
		int x0 = first_num;
		int c = f_check_increase(modulo);

		for (int i = 0; i < size_array; i++)
		{
			gen_array[i] = (a * x0 + c) % modulo;
			x0 = (a * x0 + c) % modulo;
		}
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
		return 0;
	}
	return gen_array;
}

int *f_reverse_array(int *x_array, int *&y_array, int size_array)
{
	try
	{
		//we need to add +2 to doesn't cross over the last index
		y_array = new int[size_array + 2];

		for (int i = 0; i < size_array; i++)
		{
			y_array[1 + i] = x_array[(size_array - i) - 1];
		}
		return y_array;
	}
	catch (const std::exception &)
	{
		EXCEPTION_ERROR::Create_array;
	}
}

int *f_addictive_gen(int *&y_array, int size_array, int modulo, int *pair_array)
{
	// size_array+1 because I know that k will be equal to a maximum of size_array, i.e. it will never reach the value of the last cell from which we start entering data

	int j = pair_array[0];
	int k = pair_array[1];
	int value{};
	int iterator = size_array + 1;

	for (int i = 0; i < size_array; i++)
	{
		value = (y_array[j] + y_array[k]) % modulo;
		k--;
		j--;
		if (k == 0)
			k = size_array;
		if (j == 0)
			j = size_array;

		y_array[iterator] = value;
		iterator--;
	}
	return y_array;
}