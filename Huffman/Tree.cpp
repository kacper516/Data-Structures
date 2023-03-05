#include "Tree.hpp"

Node::Node(char a, int b)
{
    sign = a;
    label = b;
    int_value = b;
}

Node::Node(char a, double b)
{
    sign = a;
    label = b;
    double_value = b;
}

bool Queue::operator()(const Node &a, const Node &b)
{
	return a.int_value > b.int_value;
}
