#pragma once

#include "Element.hpp"
#include <iostream>

class LinkedList
{
private:
    Element *head;
    Element *tail;
    int size;

public:
    /// @brief Default constructor
    LinkedList();

    /// @brief This function will check if list is empty or not
    /// @return true if empty else false
    bool empty();

    /// @brief This function will return size of list
    /// @return size of list
    int getSize();

    /// @brief This function will return pointer to first element of list
    /// @return pointer to first element of list
    Element *getFirst();

    /// @brief This function will return pointer to last element of list
    /// @return pointer to last element of list
    Element *getLast();

    /// @brief This function will return pointer to next element of list
    /// @param p pointer to element before element we search for
    /// @return pointer to the next element
    Element *getNext(Element *p);

    /// @brief This function will return pointer to previous element of list
    /// @param p pointer to element after element we search for
    /// @return pointer to the previous element
    Element *getPrev(Element *p);

    /// @brief This function will return value of element p
    /// @param p pointer to element
    /// @return value v of element p
    int retrive(Element *p);

    /// @brief This function will return frst instance of element if exist
    /// @param x value of element
    /// @return pointer to first instance of element if exist
    Element *locate(int x);

    /// @brief This function will append element x to the end of the list
    /// @param x value of new element
    void append(int x);

    /// @brief This function will append element x to the beggining of the list
    /// @param x value of new element
    void preppend(int x);

    /// @brief This function will insert new element on position p (before p)
    /// @param p pointer to element
    /// @param x value of new element
    void insert(Element *p, int x);

    /// @brief This function will delete element p
    /// @param p pointer to element
    void del(Element *p);

    /// @brief This function will clear list
    void clear();

    /// @brief This function is friendly function which we can print element in our list
    /// @param out where we can storage messege
    /// @param l pointer to linked list
    /// @return message that contain every element of linked list
    friend std::ostream &operator<<(std::ostream &out, LinkedList *l);
};