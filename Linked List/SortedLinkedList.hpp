#pragma once

#include <iostream>

#include "Element.hpp"

class SortedLinkedList
{
private:
    Element *head;
    int size;

public:
    /// @brief constructor
    SortedLinkedList();
    /// @brief This function will insert new element in non-decreasing order (ascending order)
    /// @param x value of new element
    void insertSorted(int x);

    /// @brief This function is friendly function which we can print element in our list
    /// @param out where we can storage messege
    /// @param l pointer to linked list
    /// @return message that contain every element of linked list
    friend std::ostream &operator<<(std::ostream &out, SortedLinkedList *l);
};