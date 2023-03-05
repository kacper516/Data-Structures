#include "SortedArrayList.hpp"

SortedArrayList::SortedArrayList(int c)
{
    capacity = c;
    items = new int[c];
}

// sorted in ascending order
void SortedArrayList::insertSorted(int x)
{
    if (size + 1 == capacity)
    {
        std::cout << "Wrong index we don't have more capacity";
        return;
    }

    if (head == -1)
    {
        head += 1;
        tail += 1;
        items[head] = x;
        return;
    }

    int temp = head;
    tail += 1;
    size += 1;

    while (temp != tail && items[temp] <= x)
        temp++;

    for (int i = tail; i >= temp; i--)
        items[i + 1] = items[i];

    items[temp] = x;
}

void SortedArrayList::f_print()
{
    for (int i = 0; i <= tail; i++)
        std::cout << items[i] << " ";
}

SortedArrayList::~SortedArrayList()
{
    size = 0;
    capacity = 0;
    head = -1;
    tail = -1;
}
