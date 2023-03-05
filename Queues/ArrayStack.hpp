#pragma once

#include <iostream>

class ArrayStack
{
private:
    int *items;   // array with elements
    int capacity; // capacity of array
    int top;      // index of top, last put element
public:
    /// @brief Constructor
    /// @param c capacity of stack
    ArrayStack(int c);

    /// @brief This function will check if stack is empty or not
    /// @return true if empty, else false
    bool empty();

    /// @brief This function will check if stack is full or not
    /// @return true if full, else false
    bool full();

    /// @brief This function will place new value on the top of stack
    /// @param x value of new top
    void push(int x);

    /// @brief This function will return top of the stack
    /// @return value of top
    int peek();

    /// @brief This function will delete top of the stack
    void pop();

    /// @brief This function will clear every element in stack
    void clear();

    /// @brief This function will print every element in stack
    /// @param out param which we can return every elment
    /// @param s addres to array stack
    /// @return the messege that contain every element
    friend std::ostream &operator<<(std::ostream &out, ArrayStack &s);

    /// @brief Destructor
    ~ArrayStack();
};
