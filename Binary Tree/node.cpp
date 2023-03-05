#include "node.hpp"

node::node(int v, node *l, node *r, node *p)
{
    this->value = v;
    this->left = l;
    this->right = r;
    this->parent = p;
}

int node::getValue()
{
    return value;
}

node *node::getLeft()
{
    return left;
}

node *node::getRight()
{
    return right;
}

node *node::getParent()
{
    return parent;
}

void node::setValue(int v)
{
    this->value = v;
}

void node::setLeft(node *l)
{
    this->left = l;
}

void node::setRight(node *r)
{
    this->right = r;
}

void node::setParent(node *p)
{
    this->parent = p;
}
