/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef ENTRANCEHALL_HPP_INCLUDED
#define ENTRANCEHALL_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: EntranceHall
DESCRIPTION: EntranceHall represents the entrance to the temple in the
game. Introduces the situation to the Player. EntranceHall is a
subclass of Space.
*********************************************************************/
class EntranceHall: public Space
{
    protected:
    public:
        EntranceHall(Interactable*);
        virtual ~EntranceHall();
        virtual spaceType getSpaceType();
        virtual void special();
};

#endif // ENTRANCEHALL_HPP_INCLUDED
