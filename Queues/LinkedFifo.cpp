#include "LinkedFifo.hpp"

LinkedFifo::LinkedFifo()
{
    this->head = nullptr;
    this->tail = nullptr;
}

bool LinkedFifo::empty()
{
    if (head == nullptr)
        return true;
    return false;
}

void LinkedFifo::enqueue(int x)
{
    if (head == nullptr)
    {
        head = new Element(x, nullptr);
        tail = head;
    }
    else
    {
        Element *el = new Element(x, nullptr);
        tail->setNext(el);
        tail = el;
    }
}

int LinkedFifo::peek()
{
    return head->getValue();
}

void LinkedFifo::dequeue()
{
    if (empty())
        std::cout << "You can't dequeue any element, there is no element in this queue.";
    else
    {
        Element *temp = head;
        head = head->getNext();
        delete temp;
    }
}

void LinkedFifo::clear()
{
    Element *temp = head;
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

LinkedFifo::~LinkedFifo()
{
    Element *temp = head;
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

std::ostream &operator<<(std::ostream &out, LinkedFifo *f)
{
    Element *temp = f->head;

    while (temp != nullptr)
    {
        out << temp->getValue() << " ";
        temp = temp->getNext();
    }
    return out;
}