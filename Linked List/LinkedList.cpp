#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

bool LinkedList::empty()
{
    if (size == 0)
        return true;
    return false;
}

int LinkedList::getSize()
{
    return size;
}

Element *LinkedList::getFirst()
{
    return head;
}

Element *LinkedList::getLast()
{
    return tail;
}

Element *LinkedList::getNext(Element *p)
{
    return p->getNext();
}

Element *LinkedList::getPrev(Element *p)
{
    return p->getPrev();
}

int LinkedList::retrive(Element *p)
{
    return p->getValue();
}

Element *LinkedList::locate(int x)
{
    Element *temp = head;
    while (temp != nullptr)
    {
        if (temp->getValue() == x)
            return temp;
        else
            temp = temp->getNext();
    }

    // if doesn't exist
    return nullptr;
}

void LinkedList::append(int x)
{
    if (head == nullptr)
    {
        Element *new_element = new Element(x, nullptr, nullptr);
        head = new_element;
        tail = head;
        size++;
    }
    else
    {
        Element *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }

        // prev element is temp, next element is nullptr
        Element *new_element = new Element(x, nullptr, temp);
        temp->setNext(new_element);
        tail = new_element;
        size++;
    }
}

void LinkedList::preppend(int x)
{
    // new element will be our new head
    Element *new_element = new Element(x, head, nullptr);
    head->setPrev(new_element);
    head = new_element;
    size++;
}

void LinkedList::insert(Element *p, int x)
{
    // next value will be p element, prev value will be element after p
    Element *new_element = new Element(x, p, p->getPrev());
    p->setPrev(new_element);
    size++;
}

void LinkedList::del(Element *p)
{
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    delete p;
    size--;
}

void LinkedList::clear()
{
    Element *temp = head;
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

std::ostream &operator<<(std::ostream &out, LinkedList *l)
{
    Element *temp = l->head;
    while (temp != nullptr)
    {
        out << temp->getValue() << " ";
        temp = temp->getNext();
    }
    return out;
}

LinkedList::~LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}