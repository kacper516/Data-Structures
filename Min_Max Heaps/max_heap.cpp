#include "max_heap.hpp"

max_heap::max_heap(int c)
{
    this->capacity = c;
    this->size = 0;
    this->heap = new int[this->capacity];

    for (int i = 0; i < this->capacity; i++)
        heap[i] = INT_MIN;
}

max_heap::max_heap()
{
    this->capacity = 0;
    this->size = 0;
    this->heap = nullptr;
}

bool max_heap::empty()
{
    if (size == 0)
        return true;

    return false;
}

bool max_heap::full()
{
    if (size == capacity)
        return true;

    return false;
}

int max_heap::getLeft(int i)
{
    int left_son = (2 * i) + 1;

    if (left_son > size || left_son < 0) // node left_son doesn't exist
        return -1;

    return left_son;
}

int max_heap::getRight(int i)
{
    int right_son = (2 * i) + 2;

    if (right_son < 0 || right_son > size) // node right_son doesn't exist
        return -1;

    return right_son;
}

int max_heap::getParent(int i)
{
    int parent = (i - 1) / 2;

    if (i < 0 || i > size) // node parent doesn't exist
        return -1;

    return parent;
}

int max_heap::getSize()
{
    return size;
}

void max_heap::setCapacity(int c)
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

void max_heap::setSize(int s)
{
    this->size = s;
}

int max_heap::getValue(int i)
{
    if (i < 0 || i > size) // node i doesn't exist
        return INT_MIN;

    return heap[i];
}

void max_heap::setValue(int i, int x)
{
    if (i < 0 || i > size) // node i doesn't exist
        return;

    heap[i] = x;
    // only one function of this two will execute depending on the need
    topDown(i);
    bottomUp(i);
}

void max_heap::bottomUp(int i)
{
    if (i >= 0 && i < size) // node i exist
    {
        // we need to have value of parent
        int parent = getParent(i);

        while (heap[parent] < heap[i] && parent != -1)
        {
            std::swap(heap[parent], heap[i]);

            std::swap(heap[parent], heap[i]);

            i = parent;
            parent = getParent(i);
        }
    }
}

void max_heap::topDown(int i)
{
    // if element is smaller than one of his sons we need to swap them
    int max = i;
    if (i >= 0 && i < size) // node i exist
    {
        int left_son = getLeft(i);
        int right_son = getRight(i);

        if (heap[i] < heap[left_son] && left_son != -1)
            max = left_son;

        if (heap[max] < heap[right_son] && right_son != -1)
            max = right_son;

        if (max != i)
        {
            std::swap(heap[max], heap[i]);
            topDown(max); // now we need to sink element max
        }
    }
}

void max_heap::insert(int x)
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

void max_heap::deleteMax()
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

int max_heap::maximum()
{
    if (!empty())
        return heap[0];

    return INT_MIN; // if heap is empty
}

void max_heap::del(int i)
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

void max_heap::increaseKey(int i, int x)
{
    if (i >= 0 && i < size)
    {
        // if we increase key value of node i we need to surface it
        heap[i] = x;
        bottomUp(i);
    }
}

std::ostream &operator<<(std::ostream &out, max_heap &h)
{
    for (int i = 0; i < h.size; i++)
        out << h.heap[i] << " ";

    return out << std::endl;
}
