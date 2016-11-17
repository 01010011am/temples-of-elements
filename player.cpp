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
#include "player.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: Player::Player()
PARAMETERS: None
DESCRIPTION: Sets Player's default stats.
*********************************************************************/
Player::Player()
{
    healthPoints = 8;
    numberOfAttackDice = 2;
    sidesOfAttackDice = 6;
    numberOfDefendDice = 1;
    sidesOfDefendDice = 6;
}

/*********************************************************************
FUNCTION: interactableType Player::getInteractableType()
PARAMETERS: None
DESCRIPTION: Returns interactableType, in this case PLAYER.
*********************************************************************/
interactableType Player::getInteractableType()
{
    return PLAYER;
}


/*********************************************************************
FUNCTION: int Player::attack()
PARAMETERS: None
DESCRIPTION: Initiates the Player's attack sequence.
*********************************************************************/
int Player::attack()
{
    int attackPoints = 0;

    std::cout << "\nATTACKING: YOU\n";

    attackPoints = rollDiceAttack();

    std::cout << "YOUR ATTACK IS WORTH " << attackPoints << " DAMAGE!\n";

    return attackPoints;
}


/*********************************************************************
FUNCTION: void Player::defend()
PARAMETERS: int
DESCRIPTION: Initiates the Player's defend sequence.
*********************************************************************/
void Player::defend(int a)
{
    int attackPoints = a;
    int defendPoints = 0;
    int difference = 0;

    std::cout << "\nDEFENDING: YOU\n";

    defendPoints = rollDiceDefend();

    std::cout << "YOU WERE CAPABLE OF BLOCKING " << defendPoints << " DAMAGE!\n";

    difference = attackPoints - defendPoints;

    if (difference > 0)
    {
        healthPoints -= difference;
    }

    if (healthPoints > 0)
    {
        std::cout << "YOUR HP: " << healthPoints << std::endl;
    }
    else
    {
        std::cout << "YOUR HP: 0\n";
    }
}


/*********************************************************************
FUNCTION: int Player::giveGem()
PARAMETERS: int
DESCRIPTION: Add gem to backpack.
*********************************************************************/
void Player::giveGem(int g)
{
    myBackpack.addItem(g);
}


/*********************************************************************
FUNCTION: bool Player::getGem()
PARAMETERS: int
DESCRIPTION: Reterns whether or not a type of gem is in the backpack.
*********************************************************************/
bool Player::getGem(int g)
{
    myBackpack.getItem(g);
}


/*********************************************************************
FUNCTION: int Player::displayGem()
PARAMETERS: None
DESCRIPTION: Displays the gems in the backpack.
*********************************************************************/
void Player::displayGems()
{
    myBackpack.displayList();
}
