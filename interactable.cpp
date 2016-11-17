/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "interactable.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>


/*********************************************************************
FUNCTION: Interactable::Interactable()
PARAMETERS: None
DESCRIPTION: Sets moved default to false, so the Player can move.
*********************************************************************/
Interactable::Interactable()
{
    healthPoints = 0;
    numberOfAttackDice = 0;
    sidesOfAttackDice = 0;
    numberOfDefendDice = 0;
    sidesOfDefendDice= 0;
    moved = false;
    interacted = false;
    srand(time(NULL));//for random numbers
}


/*********************************************************************
FUNCTION: void Interactable::setInteracted()
PARAMETERS: bool
DESCRIPTION: Sets whether the interactable has already been interacted
with.
*********************************************************************/
void Interactable::setInteracted(bool si)
{
    interacted = si;
}


/*********************************************************************
FUNCTION: bool Interactable::getInteracted()
PARAMETERS: None
DESCRIPTION: This function gets the Interactable's health points.
*********************************************************************/
bool Interactable::getInteracted()
{
    return interacted;
}


/*********************************************************************
FUNCTION: void Interactable::setMoved()
PARAMETERS: bool
DESCRIPTION: Accepts a bool and sets moved to what what received.
*********************************************************************/
void Interactable::setMoved(bool m)
{
    moved = m;
}


/*********************************************************************
FUNCTION: bool Interactable::getMoved()
PARAMETERS: None
DESCRIPTION: Returns the bool moved.
*********************************************************************/
bool Interactable::getMoved()
{
    return moved;
}


/*********************************************************************
FUNCTION: void Interactable::setHealthPoints()
PARAMETERS: int
DESCRIPTION: This function sets the Interactable's health points.
*********************************************************************/
void Interactable::setHealthPoints(int hp)
{
    healthPoints = hp;
}


/*********************************************************************
FUNCTION: int Interactable::getHealthPoints()
PARAMETERS: None
DESCRIPTION: This function gets the Interactable's health points.
*********************************************************************/
int Interactable::getHealthPoints()
{
    return healthPoints;
}


/*********************************************************************
FUNCTION: int Interactable::rollDiceAttack()
PARAMETERS: None
DESCRIPTION: Rolls the dice paying attention to how many dice this
particular Interactable has, adds, and returns the result.
*********************************************************************/
int Interactable::rollDiceAttack()
{
    int attackPoints = 0;
    int rollResult = 0;

    for(int i = 0; i < numberOfAttackDice; i++)
    {
        rollResult = rand() % (sidesOfAttackDice - 1 + 1) + 1;

        std::cout << "Roll #" << i+1 << ": " << rollResult << std::endl;

        attackPoints += rollResult;
    }

    return attackPoints;
}


/*********************************************************************
FUNCTION: int Interactable::rollDiceDefend()
PARAMETERS: None
DESCRIPTION: Rolls the dice paying attention to how many dice this
particular Interactable has, adds, and returns the result.
*********************************************************************/
int Interactable::rollDiceDefend()
{
    int defendPoints = 0;
    int rollResult = 0;

    for(int i = 0; i < numberOfDefendDice; i++)
    {
        rollResult = rand() % (sidesOfDefendDice - 1 + 1) + 1;

        std::cout << "Roll #" << i+1 << ": " << rollResult << std::endl;

        defendPoints += rollResult;
    }

    return defendPoints;
}
