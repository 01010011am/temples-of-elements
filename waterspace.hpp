/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef WATERSPACE_HPP_INCLUDED
#define WATERSPACE_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: WaterSpace
DESCRIPTION: This class is for the Water Temple portion of the game.
The boss that resides in this level is weak against the wind stone.
*********************************************************************/
class WaterSpace: public Space
{
    protected:
    public:
        WaterSpace(Interactable*);
        virtual ~WaterSpace();
        virtual spaceType getSpaceType();
        virtual void special();
};

#endif // WATERSPACE_HPP_INCLUDED
