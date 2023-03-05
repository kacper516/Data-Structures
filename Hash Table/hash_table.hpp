#pragma once

#include <string>
#include <iostream>

class hash_table
{
public:
    std::string *T; // array with elements
    int capacity;   // capacity
    int size;       // current size

public:
    /// @brief Constructor
    /// @param c capacity of new hash table
    hash_table(int c);

    /// @brief This function will check if hash table is empty or not
    /// @return true if empty else false
    bool empty();

    /// @brief This function will check if hash table is full or not
    /// @return true if full else not
    bool full();

    /// @brief This function will count the hash value for s key
    /// @param s key
    /// @return hash value
    int hashFunction(std::string s);

    /// @brief This function will add new items to hash table
    /// @param s key value
    /// @return number of collisions (if exist, else 0)
    int insert(std::string s);

    /// @brief This function will delete key s if exist
    /// @param s key we want to delete
    void del(std::string s);

    /// @brief This function will search for s key
    /// @param s key we want to search for
    /// @return key s or empty string
    std::string search(std::string s);

    /// @brief This function will search for s key
    /// @param s key we want to search for
    /// @return number of collision (if exist, else 0)
    int search1(std::string s);

    /// @brief This function will print every element in hash table ht
    /// @param out print statement in variable
    /// @param ht hash table
    /// @return every element printed in variable out
    friend std::ostream &operator<<(std::ostream &out, hash_table &ht);
};