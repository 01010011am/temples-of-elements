/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef SPACELIST_HPP_INCLUDED
#define SPACELIST_HPP_INCLUDED
#include "space.hpp"
#include "entrancehall.hpp"
#include "waterspace.hpp"
#include "firespace.hpp"
#include "earthspace.hpp"
#include "windspace.hpp"
#include "bloodspace.hpp"
#include "interactable.hpp"
#include "player.hpp"
#include <cstddef>


/*********************************************************************
CLASS: SpaceList
DESCRIPTION: This class creates spaces and organizes them within a
linked list.
*********************************************************************/
class SpaceList
{
    protected:
        class SpaceNode
        {
            friend class SpaceList;
            Space* thisSpace;
            SpaceNode* next;
            SpaceNode(int m, Player* mc, SpaceNode* next1 = NULL)
            {
                if(m == 0)
                {
                    thisSpace = new EntranceHall(mc);
                }
                else if(m == 1)
                {
                    thisSpace = new WaterSpace(mc);
                }
                else if(m == 2)
                {
                    thisSpace = new FireSpace(mc);
                }
                else if(m == 3)
                {
                    thisSpace = new EarthSpace(mc);
                }
                else if(m == 4)
                {
                    thisSpace = new WindSpace(mc);
                }
                else if(m == 5)
                {
                    thisSpace = new BloodSpace(mc);
                }
                next = next1;
            }
        };
        SpaceNode* head;//list head pointer
    public:
        SpaceList() { head = NULL; }
        ~SpaceList();
        void add(int, Player*);
        void remove(int);
        Space* getSpace(int);
        bool isEmpty() const;
};


#endif // SPACELIST_HPP_INCLUDED
