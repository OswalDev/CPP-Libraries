#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <class Element>
class List : public Node<Element>
{
private:
    int size;
    Node<Element> *first;

public:
    // contructors
    List();

    List(Element newData);

    List(List<Element> *list);

    ~List();

    // METHODS

    int getSize(); // return size of list

    Element getPosition(int position); // return value of given position

    void isNull(); // returns true if list is empty

    void insert(Element newData, int position);

    void printList();

private:
    Element getPosition(int position, int currentPosition, Node<Element> *currentNode);

    void insertNode(Element newData, int position, int currentPosition, Node<Element> *currentNode);

    void deleteNode(int postion, int currentPosition, Node<Element> *currentNode);

    bool is(Element data); // returns true is given data is found inside the list

    void empty(); // it empties the list
};

// TEMPLATES

template <class Element>
List<Element>::List()
{
    this->size = 0;
    this->first = new Node<Element>();
}

template <class Element>
List<Element>::List(Element newData)
{
    this->size = 1;
    this->first = new Node<Element>(newData);
}

// template <class Element>
// List<Element>::List(List<Element> *listOrigen)
// {
//     this->tamano = 0;

//     this->copy(listOrigen);
// }

// template <class Element>
// List<Element>::~List()
// {
//     this->empty(this->first);
// }

template <class Element>
void List<Element>::insert(Element newData, int position, int currentPosition, Node<Element> *currentNode)
{
    if (position == 1)
    {
        Node<Element> *newNode = new Node<Element>(newData);
        newNode->modifyNext(currentNode);
        this->first = newNode;
    }
    else
    {
        if (position - 1 == currentPosition)
        {
            newNode->
        }
    }
}

template <class Element>
void List<Element>::insert(Element newData, int position)
{
    if (position > this->size + 1 || position < 1)
    {
        cout << "ERROR: fuera de rango" << endl;
    }
    else
    {
        cout << "SUCCESS: Element inserted" << endl;
    }
}

template <class Element>
int List<Element>::getSize()
{
    return (this->size);
}

template <class Element>
void List<Element>::isNull()
{
    return (this->next == NULL);
}

template <class Element>
Node<Element> *Node<Element>::getData()
{
    return (this->data);
}

template <class Element>
Node<Element> *Node<Element>::getNext()
{
    return (this->next);
}

#endif // !LIST_H