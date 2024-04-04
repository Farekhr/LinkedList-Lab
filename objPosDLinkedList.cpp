#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{
    listTail = new DNode();
    listHead = new DNode();

    listTail->prev = listHead;
    listHead->next = listTail;

    listTail->next = NULL;
    listHead->prev = NULL;

    persistHead = listHead;
    listSize = 0;
}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode *currentHead = listHead;

    while (currentHead->next != NULL)
    {
        DNode *target = currentHead;
        currentHead = currentHead->next;
        delete target;
    }

    delete currentHead;
    listTail = NULL;
    listHead = NULL;
    persistHead = NULL;
    listSize = 0;
}

int objPosDLinkedList::getSize()
{
    return listSize;
}

bool objPosDLinkedList::isEmpty()
{
   if (listSize == 0)
   {
        return true;
   }

   else
   {
        return false;
   }
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    DNode* currentNode = new DNode();
    currentNode->data = thisPos;

    currentNode->next = listHead->next;
    currentNode->prev = listHead;
    listHead->next->prev = currentNode;
    listHead->next = currentNode;

    listSize += 1;
}

void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    DNode* currentNode = new DNode();
    currentNode->data = thisPos;

    currentNode->prev = listTail->prev;
    currentNode->next = listTail;
    listTail->prev->next = currentNode;
    listTail->prev = currentNode;

    listSize += 1;
}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{
    if (index <= 0)
    {
        insertHead(thisPos);
    }

    else if (index >= (listSize - 1))
    {
        insertTail(thisPos);
    }

    else 
    {
        DNode *insertNode = new DNode();
        insertNode->data = thisPos;
        DNode *currentNode = listHead;

        for (int x = 0; x < index; x++)
        {
            currentNode = currentNode->next;
        }

        insertNode->next = currentNode->next;
        insertNode->prev = currentNode;
        currentNode->next = insertNode;
        currentNode->next->prev = insertNode;
        

        listSize += 1;
    }
}

objPos objPosDLinkedList::getHead() const
{
    return listHead->next->data;
}

objPos objPosDLinkedList::getTail() const
{
    return listTail->prev->data;
}

objPos objPosDLinkedList::get(int index) const
{
    if (index <= 0)
    {
        return getHead();
    }

    else if (index >= (listSize - 1))
    {
        return getTail();
    }

    else 
    {
        DNode *currentNode = listHead;

        for (int x = 0; x <= index; x++)
        {
            currentNode = currentNode->next;
        }

        return currentNode->data;
    }
}

objPos objPosDLinkedList::getNext()
{
    persistHead = persistHead->next;

    if(persistHead == listTail)
    {
        persistHead = listHead->next;
        return objPos(-99, 0, 0, 0, 0);
    }

    return persistHead->data;
}

void objPosDLinkedList::resetReadPos()
{
    persistHead = listHead;
}

void objPosDLinkedList::set(const objPos &thisPos, int index)
{
    if (index < 0)
    {
        index = 0;
    }

    else if (index > (listSize - 1))
    {
        index = listSize - 1;
    }

    DNode *currentNode = listHead;

    for (int x = 0; x < index + 1; x++)
    {
        currentNode = currentNode->next;
    }

    currentNode->data = thisPos;
}


objPos objPosDLinkedList::removeHead()
{
    if (isEmpty())
    {
        return objPos(-99,0,0,0,0);
    }

    DNode *currentNode = listHead->next;

    listHead->next = currentNode->next;
    currentNode->next->prev = listHead;

    objPos currentData = currentNode->data;
    delete currentNode;
    listSize -= 1;
    return currentData;
}

objPos objPosDLinkedList::removeTail()
{
    if(isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }

    DNode *currentNode = listTail->prev;

    listTail->prev = currentNode->prev;
    currentNode->prev->next = listTail;

    objPos currentData = currentNode->data;
    delete currentNode;
    listSize -= 1;
    return currentData;
}

objPos objPosDLinkedList::remove(int index)
{
    if (isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }

    if (index <= 0)
    {
        return removeHead();
    }

    else if (index >= (listSize - 1))
    {
        return removeTail();
    }

    else 
    {
        DNode *currentNode = listHead;

        for (int x = 0; x < index + 1; x++)
        {
            currentNode = currentNode->next;
        }

        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;

        objPos currentData = currentNode->data;
        delete currentNode;
        listSize -= 1;
    
        return currentData;
    }
    
}


void objPosDLinkedList::printList() const
{
    DNode* currentNode = listHead;

    cout << "Head: " << currentNode << endl;
    cout << "Dummy Header (Address: " << currentNode << endl;
    cout << "Data: ";
    currentNode->data.printObjPos();
    cout << "Next: " << currentNode->next << endl;
    cout << "Prev: " << currentNode->prev << endl;

    for (int x = 0; x < listSize; x++)
    {
        cout << "Element: " << x + 1 << "(Address: " << currentNode << endl;
        cout << "Data: ";
        currentNode->data.printObjPos();
        cout << "Next: " << currentNode->next << endl;
        cout << "Prev: " << currentNode->prev << endl;
        currentNode = currentNode->next;
    }
}


