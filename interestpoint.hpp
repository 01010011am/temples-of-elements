/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef INTERESTPOINT_HPP_INCLUDED
#define INTERESTPOINT_HPP_INCLUDED
#include "interactable.hpp"
#include "spacelist.hpp"


/*********************************************************************
CLASS: InterestPoint
DESCRIPTION: The InterestPoint class is used to represent various
objects or points of interest throughout the game. It is a subclass
of Interactable.
*********************************************************************/
class InterestPoint: public Interactable
{
    protected:
        int interestPointType;
    public:
        InterestPoint(int);
        int stoneMural();
        void sticksInscription();
        void exitGem();
        virtual interactableType getInteractableType();
        virtual int interact();
        virtual int attack() {}
        virtual void defend(int) {}
        virtual void giveGem(int) {}
        virtual bool getGem(int) {}
        virtual void displayGems() {}

};


#endif // INTERESTPOINT_HPP_INCLUDED

