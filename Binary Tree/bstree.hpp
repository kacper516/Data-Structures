#pragma once

#include "node.cpp"
#include <iostream>

class bstree
{
private:
    node *root = nullptr; // root

public:
    /// @brief This function will create empty tree (constructor)
    bstree();

    /// @brief This function will return pointer to root if exist
    /// @return pointer to root
    node *getRoot();

    /// @brief This function will check if tree is empty or not
    /// @param p pointer to root
    /// @return true if tree is empty else false
    bool empty(node *p);

    /// @brief This function will check if node is leaf or not
    /// @param n pointer to node
    /// @return true if node is leaf else false
    bool leaf(node *n);

    /// @brief This function will print element of tree with method preorder
    /// @param p pointer to root
    void preorder(node *p);

    /// @brief This function will print element of tree with method inorder
    /// @param p pointer to root
    void inorder(node *p);

    /// @brief This function will print element of tree with method postorder
    /// @param p pointer to root
    void postorder(node *p);

    /// @brief This function will return size of tree
    /// @param p pointer to root
    /// @return size of tree
    int size(node *p);

    /// @brief This function will return height of tree
    /// @param p pointer to root
    /// @return height of tree
    int hight(node *p);

    /// @brief This function will clear all node in tree
    /// @param p pointer to root
    void clear(node *p);

    /// @brief This function will insert new node to tree
    /// @param x value of new node
    void insert(int x);

    /// @brief This function will search element with the value of x
    /// @param x value we search for
    /// @return pointer to node with value x (if exist) or nullptr
    node *search(int x);

    /// @brief This function will return minimum value of node in tree
    /// @param p root
    /// @return pointer to node with minimum value in tree
    node *minimum(node *p);

    /// @brief This function will return maximum value of node in tree
    /// @param p root
    /// @return pointer to node with maximum value in tree
    node *maximum(node *p);

    /// @brief This function will search for successor of p (if exist)
    /// @param p node
    /// @return pointer to successor of p (if exist)
    node *successor(node *p);

    /// @brief This function will search for predecessor of p (if exist)
    /// @param p node
    /// @return pointer to predecessor of p (if exist)
    node *predecessor(node *p);

    /// @brief This function will delete node p
    /// @param p node
    void del(node *p);
};