/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "spacelist.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: SpaceList::~SpaceList()
PARAMETERS: None
DESCRIPTION: Frees up memory.
*********************************************************************/
SpaceList::~SpaceList()
{
    SpaceNode* temp = head;

    while(temp != NULL)//while the stack isn't empty
    {
        SpaceNode* garbage = temp;

        temp = temp->next;

        delete garbage;//delete all the things
    }
}


/*********************************************************************
FUNCTION: void SpaceList::add()
PARAMETERS: int
DESCRIPTION: Adding SpaceNodes to the SpaceList
*********************************************************************/
void SpaceList::add(int addSpace, Player* p)
{
    if(head == NULL)
    {
        head = new SpaceNode(addSpace, p);//start new list
    }
    else
    {
        SpaceNode* nodePtr = head;//starting at the head of the list

        while (nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;//go through list until we find a NULL pointer
        }

        nodePtr->next = new SpaceNode(addSpace, p);//add to the list
    }
}


/*********************************************************************
FUNCTION: Space* SpaceList::getSpace()
PARAMETERS: int
DESCRIPTION: Returns the requested type of space from the SpaceList
*********************************************************************/
Space* SpaceList::getSpace(int num)
{
    SpaceNode* nodePtr = head;

    while(nodePtr)
    {
        if (((nodePtr->thisSpace->getSpaceType()) == ENTRANCEHALL)
           && (num == 0))
        {
            return nodePtr->thisSpace;
        }
        else if (((nodePtr->thisSpace->getSpaceType()) == WATERSPACE)
           && (num == 1))
        {
            return nodePtr->thisSpace;
        }
        else if (((nodePtr->thisSpace->getSpaceType()) == FIRESPACE)
           && (num == 2))
        {
            return nodePtr->thisSpace;
        }
        else if (((nodePtr->thisSpace->getSpaceType()) == EARTHSPACE)
           && (num == 3))
        {
            return nodePtr->thisSpace;
        }
        else if (((nodePtr->thisSpace->getSpaceType()) == WINDSPACE)
           && (num == 4))
        {
            return nodePtr->thisSpace;
        }
        else if (((nodePtr->thisSpace->getSpaceType()) == BLOODSPACE)
           && (num == 5))
        {
            return nodePtr->thisSpace;
        }
        else
        {
            nodePtr = nodePtr->next;//move on to the next node
        }
    }
}


/*********************************************************************
FUNCTION: Space* SpaceList::getSpace()
PARAMETERS: int
DESCRIPTION: Returns the requested type of space from the SpaceList
*********************************************************************/
void SpaceList::remove(int num)
{
    SpaceNode* nodePtr, *prevNodePtr;

    if (!head) return;//if list is empty do nothing

    if ((head->thisSpace->getSpaceType() == num))
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    else
    {
        nodePtr = head;

        while(nodePtr != NULL && ((nodePtr->thisSpace->getSpaceType() != num)))
        {
            prevNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr)
        {
            prevNodePtr->next = nodePtr->next;
            delete nodePtr;
        }

    }
}


/*********************************************************************
FUNCTION: bool SpaceList::isEmpty() const
PARAMETERS: None
DESCRIPTION: If the stack is empty, returns true, else returns false.
*********************************************************************/
bool SpaceList::isEmpty() const
{
    if(!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
