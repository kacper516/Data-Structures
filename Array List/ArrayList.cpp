#include "ArrayList.hpp"

#include <iostream>

ArrayList::ArrayList(int c)
{
    capacity = c;
    items = new int[c];
}

bool ArrayList::empty()
{
    if (size == 0)
        return true;
    return false;
}

bool ArrayList::full()
{
    if (size == capacity)
        return true;
    return false;
}

int ArrayList::getSize()
{
    return size;
}

int ArrayList::getCapacity()
{
    return capacity;
}

int ArrayList::getFirst()
{
    return head;
}

int ArrayList::getLast()
{
    return tail;
}

int ArrayList::getNext(int p)
{
    if (p + 1 <= tail && p + 1 > head)
        return p + 1;
    std::cout << "Wrong index (list doesn't have this much elements)" << std::endl;
    return -1;
}

int ArrayList::getPrev(int p)
{
    if (p - 1 <= tail && p - 1 > head)
        return p - 1;
    std::cout << "Wrong index (list doesn't have this much elements)" << std::endl;
    return -1;
}

int ArrayList::retrieve(int p)
{
    if (p >= head && p <= tail)
        return items[p];
    // if doesn't exist
    return -1;
}

void ArrayList::append(int x)
{
    if (head == -1)
    {
        tail += 1;
        head += 1;
        items[head] = x;
    }
    else if (tail + 1 < capacity)
    {
        tail += 1;
        size += 1;
        items[tail] = x;
    }
    else
        std::cout << "Wrong index (list doesn't have this much elements)" << std::endl;
}

void ArrayList::preppend(int x)
{
    if (head == -1)
    {
        tail += 1;
        head += 1;
        items[head] = x;
    }
    else if (tail + 1 < capacity)
    {
        tail += 1;
        size += 1;
        for (int i = tail; i >= 0; i--)
            items[i + 1] = items[i];
        items[head] = x;
    }
    else
        std::cout << "Wrong index (list doesn't have this much elements)" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ArrayList &l)
{
    if (l.tail == l.head)
        out << l.items[l.head] << " ";
    else
        for (int i = 0; i <= l.tail; i++)
            out << l.items[i] << " ";
    return out;
}

void ArrayList::f_print_list()
{
    if (tail == head)
        std::cout << items[head];
    else
        for (int i = 0; i <= tail; i++)
            std::cout << items[i];
}

void ArrayList::insert(int p, int x)
{
    if (tail + 1 >= capacity)
        std::cout << "Wrong index";
    if (p >= head && p <= tail)
    {
        // rewrite values to make empty place for p
        for (int i = tail; i >= p; i--)
            items[i + 1] = items[i];
        items[p] = x;
        tail++;
        size++;
    }
    else
        std::cout << "Wrong index (list doesn't have this much elements)" << std::endl;
}

void ArrayList::del(int p)
{

    if (p >= head && p < tail)
    {
        for (int i = p; i <= tail; i++)
        {
            items[i] = items[i + 1];
        }
    }
    tail -= 1;
    size -= 1;
}

void ArrayList::clear()
{
    delete this->items;
    items = new int[capacity]{};
    this->size = 0;
    this->head = -1;
    this->tail = -1;
}

int ArrayList::locate(int x)
{
    for (int i = 0; i <= tail; i++)
        if (items[i] == x)
            return i;
    return -1;
}

void ArrayList::deleteX(int x)
{
    int j = 0;
    for (int i = 0; i <= tail; i++)
    {
        if (items[i] == x)
        {
            tail -= 1;
            size -= 1;
            i++;
        }
        items[j] = items[i];
        j++;
    }
}

void ArrayList::deleteAllX(int x)
{
    int j = 0;
    for (int i = 0; i <= tail; i++)
    {
        if (items[i] == x)
        {
            tail -= 1;
            size -= 1;
            i++;
        }
        items[j] = items[i];
        j++;
    }
}

void ArrayList::concat(ArrayList &l)
{
    int j = 0;
    if (tail + l.tail < capacity)
    {
        for (int i = tail + 1; i <= tail + l.tail + 1; i++)
        {
            items[i] = l.items[j];
            j += 1;
            size++;
        }
    }
    tail += l.tail + 1;
}

ArrayList::~ArrayList()
{
    head = -1;
    tail = -1;
    size = -1;
    capacity = -1;
    delete[] items;
}
