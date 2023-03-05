#include "LibBackpack_rec.hpp"

bool f_backpack_recursion(std::vector<int> vector_weight, std::vector<int> &vector_return, int actual_index, int max_weight)
{
	bool if_packed;

	// Condition fulfilled
	if (max_weight == 0)
		return true;
	// Exceeded boundary conditions
	else if (actual_index + 1 > vector_weight.size() or max_weight < 0)
		return false;
	vector_return.push_back(vector_weight[actual_index]);

	// we pack next item (actual_index+1), and decrease max weight about this item packed
	if_packed = f_backpack_recursion(vector_weight, vector_return, actual_index + 1, max_weight - vector_weight[actual_index]);

	// If it returns something recursion at the top, we check whether it was true or not
	if (if_packed == true)
		return if_packed;
	else
		vector_return.pop_back();
	if_packed = f_backpack_recursion(vector_weight, vector_return, actual_index + 1, max_weight);
	return if_packed;
}