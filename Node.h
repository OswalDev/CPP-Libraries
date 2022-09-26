#ifndef Node_H_
#define Node_H

#include <iostream>

using namespace std;

template <class Element>
class Node
{
private:
    Element data;
    Node<Element> *next;

public:
    // Constructors
    Node();

    Node(Element newData);

    // Methods
    void modifyData(Element newData); // it modifies the data attribute

    void modifyNext(Node<Element> *newNode); // it modifies the data of the next attribute

    bool isNull(); // validates if data is true OR False

    Element getData(); // return data

    Node<Element> *getNext(); // return pointer to next node
};

// TEMPLATES

template <class Element>
Node<Element>::Node()
{
    this->next = NULL;
}

template <class Element>
Node<Element>::Node(Element newData)
{
    this->data = newData;
    this->next = new Node<Element>();
}

template <class Element>
void Node<Element>::modifyData(Element newData)
{
    this->data = newData;

    if (this->next == NULL)
    {
        this->next = new Node<Element>();
    }
}

template <class Element>
void Node<Element>::modifyNext(Node<Element> *newNode)
{
    this->next = newNode;
}

template <class Element>
bool Node<Element>::isNull()
{
    return (this->next == NULL);
}

template <class Element>
Element Node<Element>::getData()
{
    return (this->data);
}

template <class Element>
Node<Element> *Node<Element>::getNext()
{
    return (this->next);
}

#endif