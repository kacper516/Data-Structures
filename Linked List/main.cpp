#include<iostream>

#include"LinkedList.cpp"
#include"Element.cpp"
#include"SortedLinkedList.cpp"

int main()
{
    /*
    std::cout<<std::endl<<"Zadanie 1 - test"<<std::endl;
    LinkedList* a = new LinkedList();
    std::cout<<std::endl<<"empty(): 1 - "<<a->empty();
    std::cout<<std::endl<<"getSize():  0 - "<<a->getSize();
    std::cout<<std::endl;
    a->append(10);
    a->append(20);
    a->append(30);
    a->append(40);
    a->append(50);
    a->append(60);
    Element* temp = new Element(-1,nullptr, nullptr);
    a->preppend(0);
    Element* temp1 = new Element(-10,nullptr, nullptr);
    temp->setNext(temp1);
    a->preppend(temp->getValue());
    a->insert(temp,temp1->getValue());
    std::cout<<" "<<a;*/

    SortedLinkedList * a = new SortedLinkedList();
    a->insertSorted(-50);
    a->insertSorted(13120);
    a->insertSorted(-3360);
    a->insertSorted(33210);
    a->insertSorted(230);
    a->insertSorted(403);
    std::cout<<a;
    
}