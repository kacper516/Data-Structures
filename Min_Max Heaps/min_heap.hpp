#pragma once

#include <iostream>

class min_heap
{
private:
    int *heap;    // array with elements
    int capacity; // capacity
    int size;     // current size

public:
    /// @brief Create empty heap with capacity c -> constructor
    /// @param c capacity
    min_heap(int c);

    /// @brief Create empty heap (without cpacity) -> constructor
    min_heap();

    /// @brief This function will check if heap is empty or not
    /// @return true if heap is empty else false
    bool empty();

    /// @brief This function will check if heap is full or not
    /// @return true if heap is full else false
    bool full();

    /// @brief This function will search for index of i left son node (if exist)
    /// @param i node in heap
    /// @return This function will return index of i left son node (if exist)
    int getLeft(int i);

    /// @brief This function will search for index of i right son node  (if exist)
    /// @param i node in heap
    /// @return This function will return index of i right son node (if exist)
    int getRight(int i);

    /// @brief This function will search for index of i parent node (if exist)
    /// @param i node in heap
    /// @return This function will return index of i parent node (if exist)
    int getParent(int i);

    /// @brief This function will return size of heap
    /// @return size of heap
    int getSize();

    /// @brief This function will set new capacity of heap
    /// @param c new capacity
    void setCapacity(int c);

    /// @brief This function will set new size of heap
    /// @param s new size
    void setSize(int s);

    /// @brief This function will return value of node i (if node i exist)
    /// @param i node
    /// @return value of node i
    int getValue(int i);

    /// @brief This function will set new value x of node i
    /// @param i node
    /// @param x new value
    void setValue(int i, int x);

    /// @brief This function will return heap with method bottom -> up
    /// @param i node we want to bottom -> up
    void bottomUp(int i);

    /// @brief This function will return heap with method up -> bottom
    /// @param i node we want to up -> bottom
    void topDown(int i);

    /// @brief This function will print every element in heap
    /// @param out parameter where we can put return print statement
    /// @param h address to heap
    /// @return variable, which contain every element in heap
    friend std::ostream &operator<<(std::ostream &out, min_heap &h);

    // priority queue

    /// @brief This function will insert new element to our priority queue
    /// @param x value of new element
    void insert(int x);

    /// @brief This function will delete element with the minimum value (root)
    void deleteMin();

    /// @brief This function will return minimal value of this queue
    /// @return minimal value
    int minimum();

    /// @brief This function will delete element which exist on index i (if exist)
    /// @param i index of element we want to delete
    void del(int i);

    /// @brief This function will decrease key for the value of index i
    /// @param i index of element
    /// @param x new value
    void decreaseKey(int i, int x);
};