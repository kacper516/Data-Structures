#pragma once

class node
{
private:
    int value = 0;          // value of node
    node *left = nullptr;   // pointer to left son
    node *right = nullptr;  // pointer to right son
    node *parent = nullptr; // pointer to parent

public:
    /// @brief This function will create new Node (constructor)
    /// @param v value of new node
    /// @param l pointer to left descendant
    /// @param r pointer to right descendant
    /// @param p pointer to parent of this Node
    node(int v, node *l, node *r, node *p);

    /// @brief This function will return value of node
    /// @return value of node
    int getValue();

    /// @brief This function will return pointer to left decendant of node (if exist)
    /// @return pointer to left decendant of node (if exist)
    node *getLeft();

    /// @brief This function will return pointer to right decendant of node (if exist)
    /// @return pointer to right decendant of node (if exist)
    node *getRight();

    /// @brief This function will return pointer to parent of node (if exist)
    /// @return pointer to parent of node (if exist)
    node *getParent();

    /// @brief This function will set new value to node
    /// @param v new value of node
    void setValue(int v);

    /// @brief This function will set new left decendant of node
    /// @param l pointer to new left decendandt
    void setLeft(node *l);

    /// @brief This function will set new left decendant of node
    /// @param r pointer to new right decendandt
    void setRight(node *r);
    
    /// @brief This function will set new parent of node
    /// @param p pointer to new parent
    void setParent(node *p);
};