/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef BLOODSPACE_HPP_INCLUDED
#define BLOODSPACE_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: BloodSpace
DESCRIPTION: BloodSpace represents the Blood Temple in the game.
BloodSpace is a subclass of Interactable.
*********************************************************************/
class BloodSpace: public Space
{
    protected:
    public:
        BloodSpace(Interactable*);
        virtual ~BloodSpace();
        virtual spaceType getSpaceType();
        virtual void special();
};


#endif // BLOODSPACE_HPP_INCLUDED
