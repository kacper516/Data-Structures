#include "min_heap.hpp"

min_heap::min_heap(int c)
{
	this->capacity = c;
	this->size = 0;
	this->heap = new int[this->capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		heap[i] = INT_MAX;
	}
}

min_heap::min_heap()
{
	this->capacity = 0;
	this->size = 0;
	this->heap = nullptr;
}

bool min_heap::empty()
{
	if (size == 0)
		return true;

	return false;
}

bool min_heap::full()
{
	if (size == capacity)
		return true;

	return false;
}

int min_heap::getLeft(int i)
{
	int left_son = (2 * i) + 1;

	if (left_son > size || left_son < 0) // node left_son doesn't exist
		return -1;

	return left_son;
}

int min_heap::getRight(int i)
{
	int right_son = (2 * i) + 2;

	if (right_son < 0 || right_son > size) // node right_son doesn't exist
		return -1;

	return right_son;
}

int min_heap::getParent(int i)
{
	int parent = (i - 1) / 2;

	if (i < 0 || i > size) // node parent doesn't exist
		return -1;

	return parent;
}

int min_heap::getSize()
{
	return size;
}

void min_heap::setCapacity(int c)
{
	this->capacity = c;
	int *arr = new int[this->capacity]{};

	for (int i = 0; i < size; i++)
	{
		// we need to rewrite the values there is no more option to change capacity
		arr[i] = heap[i];
	}

	heap = arr;
}

void min_heap::setSize(int s)
{
	this->size = s;
}

int min_heap::getValue(int i)
{
	if (i < 0 || i > size) // node i doesn't exist
		return INT_MIN;

	return heap[i];
}

void min_heap::setValue(int i, int x)
{
	if (i < 0 || i > size) // node i doesn't exist
		return;

	heap[i] = x;
	// only one function of this two will execute depending on the need
	topDown(i);
	bottomUp(i);
}

void min_heap::bottomUp(int i)
{
	if (i >= 0 && i < size) // node i exist
	{
		// we need to have value of parent
		int parent = getParent(i);

		while (heap[parent] > heap[i] && parent != -1)
		{
			std::swap(heap[parent], heap[i]);

			i = parent;
			parent = getParent(i);
		}
	}
}

void min_heap::topDown(int i)
{
	// if element is bigger than one of his sons we need to swap them
	int min = i;
	if (i >= 0 && i < size) // node i exist
	{
		int left_son = getLeft(i);
		int right_son = getRight(i);

		if (heap[i] > heap[left_son] && left_son != -1)
			min = left_son;

		if (heap[min] > heap[right_son] && right_son != -1)
			min = right_son;

		if (i != min)
		{
			std::swap(heap[i], heap[min]);
			topDown(min); // now we need to sink element min
		}
	}
}

void min_heap::insert(int x)
{
	if (full())
	{
		std::cout << "Heap is full." << std::endl;
		return; // heap is full
	}
	else
	{
		heap[size] = x;
		bottomUp(size); // we surface because we add x as leaf
		size++;
	}
}

void min_heap::deleteMin()
{
	// we replace root with last element then sink it
	if (empty()) // heap is empty
	{
		std::cout << "Heap is empty." << std::endl;
		return;
	}
	else
	{
		size--;
		heap[0] = heap[size];
		topDown(0); // we sink root element right now
	}
}

int min_heap::minimum()
{
	if (!empty())
		return heap[0];

	return INT_MAX; // if heap is empty
}

void min_heap::del(int i)
{
	if (i >= 0 && i < size) // node i exist
	{
		size--;
		heap[i] = heap[size];
		// only one function of this two will execute depending on the need
		topDown(i);
		bottomUp(i);
	}
}

void min_heap::decreaseKey(int i, int x)
{
	if (i >= 0 && i < size)
	{
		// if we decrease key value of node i we need to surface it
		heap[i] = x;
		bottomUp(i);
	}
}

std::ostream &operator<<(std::ostream &out, min_heap &h)
{
	for (int i = 0; i < h.size; i++)
		out << h.heap[i] << " ";

	return out << std::endl;
}
