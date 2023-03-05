#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Element
{
private:
    int v;         // value of elements
    Element *next; // pointer to next element
public:
    /// @brief Constructor
    /// @param x value of new element
    /// @param next pointer to next element
    Element(int x, Element *next);

    /// @brief This function will return value of element
    /// @return value of element
    int getValue();

    /// @brief This function will return pointer to next element
    /// @return pointer to next element
    Element *getNext();

    /// @brief This function will set next to p element
    /// @param p element we need to put to our next
    void setNext(Element *p);

    /// @brief Destructor
    ~Element();
};

#endif