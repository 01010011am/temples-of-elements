/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef EARTHSPACE_HPP_INCLUDED
#define EARTHSPACE_HPP_INCLUDED
#include "space.hpp"


/*********************************************************************
CLASS: EarthSpace
DESCRIPTION: EarthSpace represents the Earth Temple in the game.
EarthSpace is a subclass of Space.
*********************************************************************/
class EarthSpace: public Space
{
    protected:
    public:
        EarthSpace(Interactable*);
        virtual ~EarthSpace();
        virtual spaceType getSpaceType();
        virtual void special();
};

#endif // EARTHSPACE_HPP_INCLUDED
