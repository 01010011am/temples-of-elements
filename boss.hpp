/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef BOSS_HPP_INCLUDED
#define BOSS_HPP_INCLUDED
#include "interactable.hpp"
#include "space.hpp"


/*********************************************************************
CLASS: Boss
DESCRIPTION: The Boss class is used for the various bosses in the
temple. Adjusts default stats based on the space the boss is located
in. Boss is a subclass of Interactable.
*********************************************************************/
class Boss: public Interactable
{
    protected:
        int sType;
        bool gemGiven;
        Interactable* mainCharacter;
    public:
        Boss(spaceType, Interactable*);
        virtual interactableType getInteractableType();
        virtual int interact();
        virtual int attack();
        virtual void defend(int);
        virtual void giveGem(int) {}
        virtual bool getGem(int) {}
        virtual void displayGems() {}
        int waterBoss();
        int fireBoss();
        int earthBoss();
        int windBoss();
        int bloodBoss();
};

#endif // BOSS_HPP_INCLUDED
