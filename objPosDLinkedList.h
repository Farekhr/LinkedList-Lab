#ifndef OBJPOSDLINKEDLIST_H
#define OBJPOSDLINKEDLIST_H

#include "objPosList.h"
#include "objPos.h"

class objPos;

class DNode
{        
    public:
        objPos data;
        DNode* next;
        DNode* prev;
        
        DNode()
        {
            data = objPos(0,0,0,0,0);
            next = nullptr;
            prev = nullptr;
        }        
};

// Public inheritance - using ObjPosList interface
class objPosDLinkedList : public objPosList
{
    // Singly linked list with header and tail pointer
    private:
        DNode* listHead;
        DNode* listTail;
        DNode* persistHead;
        int listSize;        
        

    public:
        objPosDLinkedList();
        virtual ~objPosDLinkedList();  // polymorphic destructor

        // Once inheriting interface (Pure Abstract Class), must provide concrete implementation
        // for all the interface functions.
        int getSize();
        bool isEmpty();

        void insertHead(const objPos &thisPos);
        void insertTail(const objPos &thisPos);
        void insert(const objPos &thisPos, int index);
        
        objPos getHead() const;
        objPos getTail() const;
        objPos get(int index) const;
        objPos getNext();
        void resetReadPos();
        void set(const objPos &thisPos, int index);

        objPos removeHead();
        objPos removeTail();
        objPos remove(int index);

        void printList() const;
};


#endif