#pragma once

class Element
{
private:
    int v;         // value of element
    Element *next; // pointer to next element
    Element *prev; // pointer to previous element

public:
    /// @brief Default constructor
    Element();

    /// @brief This function is more complex constructor of element
    /// @param x value of element
    /// @param next pointer to next element
    /// @param prev pointer to previous element
    Element(int x, Element *next, Element *prev);

    /// @brief This function will return value v of element
    /// @return value of v
    int getValue();

    /// @brief This function will set value of element
    /// @param v new value of element
    void setValue(int v);

    /// @brief This function will return position of next element
    /// @return position of next element
    Element *getNext();

    /// @brief This function will return position of previous element
    /// @return position of previous element
    Element *getPrev();

    /// @brief This function will make "p" element the next element
    /// @param p next element
    void setNext(Element *p);

    /// @brief This function will make "p" element the previous element
    /// @param p previous element
    void setPrev(Element *p);
};
