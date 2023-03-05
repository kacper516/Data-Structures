#pragma once

#include "iostream"
#include "Element.cpp"

class LinkedStack
{
private:
    Element *top; // top element, last added
public:
    /// @brief Constructor
    LinkedStack();

    /// @brief This function will check if stack is empty or not
    /// @return true if empty else if not
    bool empty();

    /// @brief This function will push value x to top of our stack
    /// @param x value of new top
    void push(int x);

    /// @brief This function will return value of our top
    /// @return value of our top
    int peek();

    /// @brief This function will pop element from our stack
    void pop();

    /// @brief This function will clear our stack
    void clear();

    /// @brief This function will print every element in stack
    /// @param out param which we can return every elment
    /// @param s pointer to linked stack
    /// @return the messege that contain every element
    friend std::ostream &operator<<(std::ostream &out, LinkedStack *s);

    /// @brief Destructor
    ~LinkedStack();
};