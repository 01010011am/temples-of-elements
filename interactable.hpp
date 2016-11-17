/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef INTERACTABLE_HPP_INCLUDED
#define INTERACTABLE_HPP_INCLUDED


/*********************************************************************
CLASS: Interactable
DESCRIPTION: This class acts as the abstract class for all the objects
in the game that you can interact with, hence the name.
*********************************************************************/
enum interactableType {PLAYER, BOSS, INTERESTPOINT, PORTAL};

class Interactable
{
    protected:
        int healthPoints;
        int numberOfAttackDice;
        int sidesOfAttackDice;
        int numberOfDefendDice;
        int sidesOfDefendDice;
        bool interacted;
        bool moved;
    public:
        Interactable();

        void setInteracted(bool);
        bool getInteracted();

        void setMoved(bool);
        bool getMoved();

        int rollDiceAttack();
        int rollDiceDefend();

        void setHealthPoints(int);
        int getHealthPoints();

        virtual interactableType getInteractableType() = 0;
        virtual int interact() = 0;
        virtual int attack() = 0;
        virtual void defend(int) = 0;

        virtual void giveGem(int) = 0;
        virtual bool getGem(int) = 0;
        virtual void displayGems() = 0;
};

#endif // INTERACTABLE_HPP_INCLUDED

