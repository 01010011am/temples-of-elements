/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include "interactable.hpp"
#include "backpack.hpp"


/*********************************************************************
CLASS: Player
DESCRIPTION: The Player class is responsible for the functions of the
main character. It is a subclass of Interactable.
*********************************************************************/
class Player: public Interactable
{
    protected:
        Backpack myBackpack;
    public:
        Player();
        virtual interactableType getInteractableType();
        virtual int interact() {}
        virtual int attack();
        virtual void defend(int);
        virtual void giveGem(int);
        virtual bool getGem(int);
        virtual void displayGems();
};

#endif // PLAYER_HPP_INCLUDED
