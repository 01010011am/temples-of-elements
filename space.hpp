/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef SPACE_HPP_INCLUDED
#define SPACE_HPP_INCLUDED
#include "interactable.hpp"


/*********************************************************************
CLASS: Space
DESCRIPTION: This is the abstract base class for the various spaces in
the game. Includes special function because each type of space will
have a special action.
*********************************************************************/
enum spaceType {ENTRANCEHALL, WATERSPACE, FIRESPACE, EARTHSPACE,
                WINDSPACE, BLOODSPACE};

const int SPACESIZE = 7;
const int POISONED = 25;

class Space
{
    protected:
        Interactable* interactableGrid[SPACESIZE][SPACESIZE];
        int stepsTillPoisoned;
    public:
        bool beenHere;
        Space();//initializes space to NULL
        ~Space();
        int move(char);//allows player to move
        void clearMoved();//resets the space so Player can move again
        void display();//displays the space
        int battle(Interactable*, Interactable*);
        virtual spaceType getSpaceType() = 0;//get the space type
        virtual void special() = 0;
};

#endif // SPACE_HPP_INCLUDED
