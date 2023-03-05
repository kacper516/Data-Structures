#pragma once

#include "LibException.hpp"
#include "Tree.hpp"

#include <fstream>
#include <queue>
#include <string>

/// @brief This function will recursive fill tree with values '0' and '1'
/// @param node array fill with nodes
void f_fill_values(Node *node);

/// @brief This function will create a tree
/// @param tree quque struct of Node with overload operator (from stack overflow)
/// @param data choose between frequency or probability
void f_huffman(std::priority_queue<Node, std::vector<Node>, Queue> tree, int data);

/// @brief This function will show values of specific chars
/// @param start first node
/// @param code_value variable storing part of the encoded value
void f_show_result(Node *start, std::string code_value);
