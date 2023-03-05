#pragma once

#include <iostream>

class ArrayFifo
{
private:
    int *items;   // array of items
    int capacity; // capacity of array
    int size;     // current size of array
    int head;     // index of first element
    int tail;     // index of last element
public:
    /// @brief Constructor
    /// @param c capacity of queue
    ArrayFifo(int c);

    /// @brief This function will check if queue is empty or not
    /// @return true if empty else false
    bool empty();

    /// @brief This function will check if queue is full or not
    /// @return true if full else false
    bool full();

    /// @brief This function will add value to queue
    /// @param x value of new 'element' in queue
    void enqueue(int x);

    /// @brief This function wll return first value in queue
    /// @return first value in queue
    int peek();

    /// @brief This function will delete element from queue
    void dequeue();

    /// @brief This function will delete every element in our list
    void clear();

    /// @brief This function will print every element in queue
    /// @param out param which we can return every elment
    /// @param f addres to array fifo
    /// @return the messege contain every element
    friend std::ostream &operator<<(std::ostream &out, ArrayFifo &f);

    /// @brief Destructor
    ~ArrayFifo();
};