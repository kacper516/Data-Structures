#include "LinkedStack.hpp"

LinkedStack::LinkedStack()
{
    top = nullptr;
}

bool LinkedStack::empty()
{
    if (top == nullptr)
        return true;
    return false;
}

void LinkedStack::push(int x)
{
    if (top == nullptr)
    {
        top = new Element(x, nullptr);
    }
    else
    {
        Element *el = new Element(x, top);
        top = el;
    }
}
int LinkedStack::peek()
{
    if (!empty())
        return top->getValue();

    std::cout << "There is no element (stack is empty) ";
    return INT_MIN;
}

void LinkedStack::pop()
{
    if (!empty())
    {
        Element *temp = top;
        top = top->getNext();
        delete temp;
    }
    else
        std::cout << "There is no element (stack is empty) ";
}

void LinkedStack::clear()
{
    if (!empty())
    {
        Element *temp = nullptr;
        while (top != nullptr)
        {
            temp = top;
            top = top->getNext();
            delete temp;
        }
    }
    else
        std::cout << "There is no element (stack is empty) ";
}

LinkedStack::~LinkedStack()
{
    clear();
}

std::ostream &operator<<(std::ostream &out, LinkedStack *s)
{
    if (!s->empty())
    {
        Element *temp = s->top;
        while (temp != nullptr)
        {
            out << temp->getValue() << " ";
            temp = temp->getNext();
        }
    }
    return out;
}