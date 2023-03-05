#include "Element.hpp"

Element::Element()
{
    this->v = -1;
    this->prev = nullptr;
    this->next = nullptr;
}

Element::Element(int x, Element *next, Element *prev)
{
    this->v = x;
    this->next = next;
    this->prev = prev;
}

int Element::getValue()
{
    return v;
}

void Element::setValue(int v)
{
    this->v = v;
}

Element *Element::getNext()
{
    return next;
}

Element *Element::getPrev()
{
    return prev;
}

void Element::setNext(Element *p)
{
    this->next = p;
}

void Element::setPrev(Element *p)
{
    this->prev = p;
}

Element::~Element()
{
    v = -1;
    prev = nullptr;
    next = nullptr;
}