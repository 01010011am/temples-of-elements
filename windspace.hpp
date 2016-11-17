/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef WINDSPACE_HPP_INCLUDED
#define WINDSPACE_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: WindSpace
DESCRIPTION: WindSpace represents the Wind Temple in the game.
WindSpace is a subclass of Space.
*********************************************************************/
class WindSpace: public Space
{
    protected:
    public:
        WindSpace(Interactable*);
        virtual ~WindSpace();
        virtual spaceType getSpaceType();
        virtual void special();
};

#endif // WINDSPACE_HPP_INCLUDED
