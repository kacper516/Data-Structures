#include "alg_sort.hpp"

void selection_sort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minimum = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minimum] > arr[j])
				minimum = j;
		}

		if (minimum != i)
			std::swap(arr[minimum], arr[i]);
	}
}

void insertion_sort(int *arr, int n)
{
	// we assume that first element is on the right place
	for (int i = 1; i < n; i++)
	{
		int aux = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > aux)
		{
			arr[j + 1] = arr[j]; // rewrite the values
			j--;
		}

		arr[j + 1] = aux; // we put aux value in right place
	}
}

void bubble_sort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				std::swap(arr[i], arr[j]);
		}
	}
}

void print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

int partition(int *arr, int low, int high)
{
	// We can choose pivot in some ways i choose mid element
	int pivot = arr[(low + high) / 2]; // wybieram srodkowy element
	int i = low - 1;
	int j = high + 1;

	while (true)
	{
		do // we search for values bigger than pivot from left side (first index)
		{
			i++;
		} while (arr[i] < pivot);

		do // we search for values smaller than pivot from right side (last index)
		{
			j--;
		} while (arr[j] > pivot);

		if (i < j) // if index of i is smaller than index of j that's correct
			std::swap(arr[i], arr[j]);
		else // else return the index of pivot
			return j;
	}
}

void quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, pivot + 1, high);
		quick_sort(arr, low, pivot);
	}
}

void counting_sort(int *arr, int n)
{
	int max = max_value(arr, n);

	// an array that contains the number of occurrences
	int *counting_arr = new int[max + 1]{};

	for (int i = 0; i < n; i++)
	{
		int value_on_index_i = arr[i];
		counting_arr[value_on_index_i]++; // we increment occurence of value
	}

	int index = 0; // helping index
	for (int i = 0; i < max + 1; i++)
	{
		for (int j = 0; j < counting_arr[i]; j++)
		{
			// if we have some values on index i we need to put them in right index
			//  i is value we need to put, on counting_arr[i] we have numbers of occurences of this value
			arr[index] = i;
			index++;
		}
	}
}

int max_value(int *arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

int min_value(int *arr, int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

void build_maxheap(int *arr, int n)
{
	/*
		we know that in heap leaf automatically satisfy the properties of the heap (they don't have sons)
		Internal nodes are only to the left of the half of the array (in the case of a complete heap),
		so traversing from the middle of the array to the beginning allows us to build a maximum heap from the array.
	*/
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i); // we build heap type max
}

void heapify(int *arr, int n, int i)
{
	// we need to sink values to down
	int max = i;
	int left_son = 2 * i + 1;
	int right_son = 2 * i + 2;

	if (arr[left_son] > arr[max] && left_son < n)
		max = left_son;

	if (arr[right_son] > arr[max] && right_son < n)
		max = right_son;

	if (max != i) // we need to replace this element
	{
		std::swap(arr[i], arr[max]);

		heapify(arr, n, max); // now we need to sink max value if we need to
	}
}

void heap_sort(int *arr, int n)
{
	build_maxheap(arr, n); // we build max heap from array

	/*
		We need to take maximum value of heap (max value is on index 0),
		then we replace max value with the minimum value, then we need to sink this value
	*/

	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}