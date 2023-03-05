#pragma once

class Node
{
public:
	Node *left = nullptr;
	Node *right = nullptr;
	Node *root = nullptr;

	char sign = '\0';

	double double_value = 0;

	int int_value = 0, label = 0;

	/// @brief This is constructor for frequency case
	/// @param a sign
	/// @param b label and int value
	Node(char a, int b);

	/// @brief This is constructor for frequency case
	/// @param a sign
	/// @param b label and double value
	Node(char a, double b);
};

struct Queue
{
	/// @brief This function will create queue of class Node with overload operator
	/// @param a first node
	/// @param b second node
	/// @return bigger value
	bool operator()(const Node &a, const Node &b);
};
