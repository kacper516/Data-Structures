#pragma once

#include <iostream>

#include "Element.hpp"

class LinkedFifo
{
private:
    Element *head; // first element in list
    Element *tail; // second element in list
public:
    /// @brief Constructor
    LinkedFifo();

    /// @brief This function will check if queue is empty or not
    /// @return true if empty else, return false
    bool empty();

    /// @brief This function will ad new element to our queue
    /// @param x value of new element
    void enqueue(int x);

    /// @brief This function will return first element in our queue
    /// @return value of first element in our queue
    int peek();

    /// @brief This function will delete first element in our queue (if exist)
    void dequeue();

    /// @brief This function will clear our queue
    void clear();

    /// @brief This function will print every element in queue
    /// @param out param which we can return every elment
    /// @param f pointer to linked fifo queue
    /// @return the messege contain every element
    friend std::ostream &operator<<(std::ostream &out, LinkedFifo *f);

    /// @brief Destructor
    ~LinkedFifo();
};
