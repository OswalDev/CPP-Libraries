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
    // CONSTRUCTORS
    List(); // it creates an empty list

    List(Element newData); // it creates a list with given data as unique node

    List(List<Element> *srcList); // it creates a list given another list

    ~List();

    // PUBLIC METHODS

    int length(); // return size of list

    Element getPosition(int position); // return value of given position

    bool isNull(); // returns true if list is empty

    void insertNode(Element newData, int position);

    void printListHorizontally();

    void printListVertically();

    bool is(Element data); // returns true if given data exits in the list

    void invert(); // it inverts the list

    void empty(); // it empties the list

    void copy(List<Element> *srcList);

    void selectionSort(); // Sorting algorithm

private:
    // PRIVATE METHODS
    Element getPosition(int position, int currentPosition, Node<Element> *currentNode);

    void increaseSize(); // it increases

    void decreaseSize(); // it increases

    void insertNode(Element newData, int position, int currentPosition, Node<Element> *currentNode);

    bool is(Element data, Node<Element> *currentNode); // returns true is given data is found inside the list

    void deleteNode(int postion, int currentPosition, Node<Element> *currentNode);

    void empty(Node<Element> *currentNode); // it empties the list

    void selectionSort(List<Element> *unorderedList); // Sorting algorithm

    Node<Element> *minSort(Node<Element> *currentNode, Element *minData); // it searches the min of unordered list and it deletes it
};

// TEMPLATES

/* -------------------------- CONSTRUCTORS TEMPLATES ----------------------------- */

/* -------------------------- PUBLIC TEMPLATES ----------------------------- */

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

template <class Element>
List<Element>::List(List<Element> *srcList)
{
    this->size = 0;
    this->copy(srcList);
}

template <class Element>
List<Element>::~List()
{
    this->empty(this->first);
}

template <class Element>
int List<Element>::length()
{
    return (this->size);
}

template <class Element>
Element List<Element>::getPosition(int position)
{
    Element result;
    if (this->size == 0 || position > this->size)
    {
        // if given position exceeds list size
        std::cout << "ERROR: this postion is not reachable" << std::endl;
    }
    else
    {
        result = this->getPosition(position, 1, this->first);
    }

    return (result);
}

template <class Element>
bool List<Element>::isNull()
{
    return (this->size == 0);
}

template <class Element>
void List<Element>::insertNode(Element newData, int position)
{
    if (position > this->size + 1 || position < 1)
    {
        std::cout << "ERROR: position out of range" << std::endl;
    }
    else
    {
        this->insertNode(newData, position, 1, this->first);
        this->increaseSize();
    }
}

template <class Element>
void List<Element>::printListHorizontally()
{
    Node<Element> *currentNode = this->first;

    while (!currentNode->isNull())
    {
        std::cout << currentNode->getData() << " ," << std::endl;
    }
}

template <class Element>
void List<Element>::printListVertically()
{
    Node<Element> *currentNode = this->first;

    while (!currentNode->isNull())
    {
        std::cout << currentNode->getData() << std::endl;
        currentNode = currentNode->getNext;
    }
}

template <class Element>
bool List<Element>::is(Element data)
{
    bool result = false;

    if (!this->isNull())
    {
        result = this->is(data, this->first);
    }

    return (result);
}

template <class Element>
void List<Element>::invert()
{
    if (!this->isNull())
    {
        Node<Element> *current;
        Node<Element> *prev;
        Node<Element> *next;

        current = this->first;
        prev = new Node<Element>();
        next = NULL;

        while (!current->isNull())
        {
            next = current->getNext();
            current->modifyNext(prev);
            prev = current;
            current = next;
        }
        this->first = prev;
    }
}

template <class Element>
void List<Element>::insertNode(Element newData, int position, int currentPosition, Node<Element> *currentNode)
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
            Node<Element> *newNode = new Node<Element>(newData);
            newNode->modifyNext(currentNode->getNext());
            currentNode->modifyNext(newNode);
        }
        else
        {
            this->insertNode(newData, position, currentPosition + 1, currentNode->getNext());
        }
    }
}

template <class Element>
void List<Element>::insertNode(Element newData, int position, int currentPosition, Node<Element> *currentNode)
{
    if (position == 1)
    {
        Node<Element> *newNode = new Node<Element>(newData);
        newNode->modifyNext(currentNode);
    }
    else
    {
        cout << "SUCCESS: Element inserted" << endl;
    }
}

template <class Element>
int List<Element>::length()
{
    return (this->size);
}

template <class Element>
bool List<Element>::isNull()
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

/* -------------------------- PRIVATE METHODS ----------------------------- */

template <class Element>
Element List<Element>::getPosition(int position, int currentPosition, Node<Element> *currentNode)
{
    Element result;

    if (position == currentPosition)
    {
        result = currentNode->getData();
    }
    else
    {
        result = this->getPosition(position, currentPosition + 1, currentNode->getNext());
    }

    return (result);
}

#endif // !LIST_H