/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef FIRESPACE_HPP_INCLUDED
#define FIRESPACE_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: FireSpace
DESCRIPTION: FireSpace represents the Fire Temple in the game.
FireSpace is a subclass of Space.
*********************************************************************/
class FireSpace: public Space
{
    protected:
    public:
        FireSpace(Interactable*);
        virtual ~FireSpace();
        virtual spaceType getSpaceType();
        virtual void special();
};

#endif // FIRESPACE_HPP_INCLUDED
