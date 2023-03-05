#pragma once

#include <ostream>

class ArrayList
{
private:
    int *items;
    int head = -1;    // index of first element
    int tail = -1;    // index of last elements
    int capacity = 0; // array size
    int size = 0;     // number of elements in array

public:
    /// @brief Constructor, this function will create empty list of capacity c
    /// @param c capacity of our list (array in list)
    ArrayList(int c);

    /// @brief This function will check if list are empty or not
    /// @return True if empty, false if not
    bool empty();

    /// @brief This function will check if list are empty or not
    /// @return True if empty, false if not
    bool full();

    /// @brief This function will return current size of array list
    /// @return size of array list
    int getSize();

    /// @brief This function will return capacity of array list
    /// @return size of array list
    int getCapacity();

    /// @brief This function will return position of first element in array list
    /// @return index to first element
    int getFirst();

    /// @brief This function will return position of first element in array list
    /// @return index to first element
    int getLast();

    /// @brief This function will return position of next element after p (if exist!)
    /// @param p index of elment we search next for
    /// @return position of element after p (if exist!)
    int getNext(int p);

    /// @brief This function will return position of previous element after p (if exist!)
    /// @param p index of elment we search previous for
    /// @return position of element after p (if exist!)
    int getPrev(int p);

    /// @brief This function will return an element of postion p (if exist!)
    /// @param p position of element we want to check
    /// @return value of element in position p (if exist!)
    int retrieve(int p);

    /// @brief This function will append element on the end of the list
    /// @param x number we want to append to our list
    void append(int x);

    /// @brief This function will preppend element on the beggining of the list
    /// @param x number we want to preppend to our list
    void preppend(int x);

    /// @brief This function will take advantages of overload function to prin every elements in list
    /// @param out parameter which we can return value
    /// @param l list we want to print
    /// @return overload out
    friend std::ostream &operator<<(std::ostream &out, ArrayList &l); // wypisuje elementu listy

    /// @brief This function will print every elements in list
    void f_print_list();

    /// @brief This function will insert number x on the postion p (if postion p exist!)
    /// @param p position where x must be insert
    /// @param x number we need to put on this position
    void insert(int p, int x);

    /// @brief This function will delete an element from position p (if this position exist)
    /// @param p position of element we want to delete
    void del(int p);

    /// @brief This function will delete every elements in list
    void clear();

    /// @brief This function will return first instance of x if exist if not -1
    /// @param x number we want to search
    /// @return index of first instane of x or -1 if not exist
    int locate(int x);

    /// @brief This function will delete first instance of x if exist
    /// @param x number we search for
    void deleteX(int x);

    /// @brief This function will delete all isntances of x if exists
    /// @param x number we search for
    void deleteAllX(int x);

    /// @brief This function will append another list to our current list
    /// @param l list we want to append to our list
    void concat(ArrayList &l);
};
