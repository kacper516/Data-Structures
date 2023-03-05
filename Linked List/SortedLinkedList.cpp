#include "SortedLinkedList.hpp"

SortedLinkedList::SortedLinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

SortedLinkedList::~SortedLinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

void SortedLinkedList::insertSorted(int x)
{
    if (head == nullptr)
    {
        head = new Element(x, nullptr, nullptr);
    }
    else
    {
        if (head->getValue() > x)
        {
            Element *el = new Element(x, head, nullptr);
            head->setPrev(el);
            head = el;
            return; // to exit earlier function
        }
        Element *temp = head;
        while (temp->getNext() != nullptr && temp->getNext()->getValue() < x)
            temp = temp->getNext();

        Element *el = new Element(x, temp->getNext(), temp);
        temp->setNext(el);
    }

    // in any option it will be increased by one
    size += 1;
}

std::ostream &operator<<(std::ostream &out, SortedLinkedList *l)
{
    while (l->head != nullptr)
    {
        out << l->head->getValue() << " ";
        l->head = l->head->getNext();
    }
    return out;
}