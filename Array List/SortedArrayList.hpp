#pragma once

#include <iostream>

class SortedArrayList
{
    int size = 0;     // current size
    int head = -1;    // index of head
    int tail = -1;    // index of tail
    int capacity = 0; // capacity
    int *items;       // array fill with items

public:
    /// @brief Constructor, this function will create our list with capacity c
    /// @param c capacity of our list
    SortedArrayList(int c);

    /// @brief This function will insert x on sorted position
    /// @param x number we want to put into our list
    void insertSorted(int x);

    /// @brief This function will print elements in list
    void f_print();
};
