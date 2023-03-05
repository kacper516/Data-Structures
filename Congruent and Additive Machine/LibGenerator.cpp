#include "LibGenerator.hpp"

std::vector<int> f_prime_factors(int num)
{
	std::vector<int> prime_factors;
	prime_factors.push_back(1); // it is always 1
	int k = 2;
	while (num > 1)
	{
		if (num % k == 0)
		{
			prime_factors.push_back(k);
			num = num / k;
		}
		else
		{
			k++;
		}
	}
	return prime_factors;
}

void f_show_pf(std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

int f_NWD(int first_numb, int second_numb)
{
	while (first_numb != second_numb)
	{
		if (first_numb > second_numb)
			first_numb -= second_numb;
		else
			second_numb -= first_numb;
	}

	// we can also return first number because first number = second number
	return second_numb;
}

int f_check_increase(int num_range)
{
	// because if 1, it would always be NWD
	for (int increase = 2; increase < num_range; increase++)
	{
		if (f_NWD(increase, num_range) == 1)
			return increase;
	}
}

int f_check_multiplier(int num_range)
{
	int multiplier = 2;
	int best_lambda = 1;
	long result = 0;

	std::vector<int> possible_multiplier;

	// iteration on a to find the best
	for (multiplier; multiplier < num_range; multiplier++)
	{
		if (f_NWD(multiplier, num_range) == 1)
		{
			int lambda = 1;
			result = pow(multiplier, lambda);
			// boundary condition, when long reaches such large values that it goes out of its range generates numbers na - then the loop will exit

			while (result > 0)
			{
				// we must check if new lambda is bigger than the best to this time
				if (result % num_range == 1)
				{
					if (lambda > best_lambda)
					{
						best_lambda = lambda;
						possible_multiplier.clear();

						// save a with the biggest labda
						possible_multiplier.push_back(multiplier);
					}
					// if 2 lambdas are the same
					else if (lambda == best_lambda)
					{
						possible_multiplier.push_back(multiplier);
					}

					// if we found value we need to go to next iteration
					break;
				}
				lambda++;
				result = pow(multiplier, lambda);
			}
		}
	}

	// value which has got information of a_max if none have been fulfilled
	int multiplier_max = 1;

	for (int i = 0; i < possible_multiplier.size(); i++)
	{
		if (f_first_condition(num_range, possible_multiplier[i]) and f_second_condition(num_range, possible_multiplier[i]))
		{
			return possible_multiplier[i];
		}
	}

	// if before we don't return any value we'll return biggest multiplier
	if (multiplier_max == 1 and possible_multiplier.size() > 0)
	{
		// there is the biggest a
		multiplier_max = possible_multiplier.back();
		return multiplier_max;
	}
	return multiplier_max;
}

bool f_first_condition(int num_range, int multiplier)
{
	std::vector<int> prime_factor_vector;
	prime_factor_vector = f_prime_factors(num_range);
	int b = multiplier - 1;

	for (int i = 0; i < prime_factor_vector.size(); i++)
	{
		if (b % prime_factor_vector[i] != 1)
			return false;
	}
	return true;
}

bool f_second_condition(int num_range, int multiplier)
{
	int b = multiplier - 1;
	if (num_range % 4 == 0)
	{
		if (b % 4 == 0)
			return true;
	}
	return false;
}