/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "interactable.hpp"
#include "boss.hpp"
#include "space.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: Boss::Boss()
PARAMETERS: spaceType
DESCRIPTION: Specifies the Boss based on the space that the Boss is
located in.
*********************************************************************/
Boss::Boss(spaceType st, Interactable* mc)
{
    sType = st;
    healthPoints = 20;
    numberOfAttackDice = 2;
    sidesOfAttackDice = 6;
    numberOfDefendDice = 1;
    sidesOfDefendDice = 6;
    gemGiven = false;
    mainCharacter = mc;
}


/*********************************************************************
FUNCTION: interactableType Boss::getInteractableType()
PARAMETERS: None
DESCRIPTION: Returns the interactableType, in this case BOSS.
*********************************************************************/
interactableType Boss::getInteractableType()
{
    return BOSS;
}


/*********************************************************************
FUNCTION: int Boss::interact()
PARAMETERS: None
DESCRIPTION: The Boss' interaction code. Defines how the Boss behaves
with the Player.
*********************************************************************/
int Boss::interact()
{
    if (sType == 1)
    {
        waterBoss();
    }
    else if (sType == 2)
    {
        fireBoss();
    }
    else if (sType == 3)
    {
        earthBoss();
    }
    else if (sType == 4)
    {
        windBoss();
    }
}


/*********************************************************************
FUNCTION: int Boss::attack()
PARAMETERS: None
DESCRIPTION: Initiates the Boss' attack sequence.
*********************************************************************/
int Boss::attack()
{
    int attackPoints = 0;

    std::cout << "\nATTACKING: TEMPLE GOD\n";

    attackPoints = rollDiceAttack();

    std::cout << "THE TEMPLE GOD'S ATTACK IS WORTH " << attackPoints << " DAMAGE!\n";

    return attackPoints;
}


/*********************************************************************
FUNCTION: void Boss::defend()
PARAMETERS: int
DESCRIPTION: Initiates the Boss' defend sequence.
*********************************************************************/
void Boss::defend(int a)
{
    int attackPoints = a;
    int defendPoints = 0;
    int difference = 0;

    std::cout << "\nDEFENDING: TEMPLE GOD\n";

    defendPoints = rollDiceDefend();

    std::cout << "THE TEMPLE GOD WAS CAPABLE OF BLOCKING " << defendPoints << " DAMAGE!\n";

    difference = attackPoints - defendPoints;

    if (difference > 0)
    {
        healthPoints -= difference;
    }

    if (healthPoints > 0)
    {
        std::cout << "TEMPLE GOD HP: " << healthPoints << std::endl;
    }
    else
    {
        std::cout << "TEMPLE GOD HP: 0\n" << std::endl;
    }
}


/*********************************************************************
FUNCTION: int Boss::waterBoss()
PARAMETERS: None
DESCRIPTION: The Water God's interaction set.
*********************************************************************/
int Boss::waterBoss()
{
    if (interacted == false)
    {
        char choice;

        std::cout << "WATER GOD: \"Are you ready to fight me for this WATER GEM?\"\n";

        do
        {
            std::cout << "Y/N: ";
            std::cin >> choice;

            if(choice == 'y' || choice == 'Y')
            {
                if (mainCharacter->getGem(3))//if player has earth gem
                    mainCharacter->setHealthPoints(40);//advantage

                return 1;//fight
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "WATER GOD: \"Return when you're ready.\"\n";

                return 9;//return to map
            }

        }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
    }
    else if (interacted == true && gemGiven == false)
    {

        if (mainCharacter->getGem(1))//if mainCharacter already has water gem
        {
            std::cout << "WATER GOD: \"Oh, it looks like you already have a water gem.\"\n";

            gemGiven = true;

            return 0;//gets nothing
        }
        else
        {
            std::cout << "Health replenished and received WATER GEM!\n";

            gemGiven = true;

            return 1;//1 = return water gem
        }

    }
    else if (interacted == true && gemGiven == true)
    {
        std::cout << "WATER GOD: \"Snitches get stitches, dolphin...\"\n";

        return 0;
    }
}


/*********************************************************************
FUNCTION: int Boss::fireBoss()
PARAMETERS: None
DESCRIPTION: The Fire God's interaction set.
*********************************************************************/
int Boss::fireBoss()
{
    if (interacted == false)
    {
        char choice;

        std::cout << "FIRE GOD: \"You'll have to defeat me to get this FIRE GEM. Ready to die?\"\n";

        do
        {
            std::cout << "Y/N: ";
            std::cin >> choice;

            if(choice == 'y' || choice == 'Y')
            {
                if (mainCharacter->getGem(1))//if player has water gem
                    mainCharacter->setHealthPoints(40);//advantage

                return 1;//fight
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "FIRE GOD: \"Pathetic.\"\n";

                return 9;//return to map
            }

        }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
    }
    else if (interacted == true && gemGiven == false)
    {
        if (mainCharacter->getGem(2))
        {
            std::cout << "FIRE GOD: \"Well, well, well, look who already has a fire gem.\"\n";

            gemGiven = true;

            return 0;
        }
        else
        {
            std::cout << "Health replenished and received FIRE GEM.\n";

            gemGiven = true;

            return 2;//2 = return fire gem
        }
    }
    else if (interacted == true && gemGiven == true)
    {
        std::cout << "FIRE GOD: \"Be gone before I set everything that you've ever loved on fire.\"\n";
        return 0;
    }
}


/*********************************************************************
FUNCTION: int Boss::earthBoss()
PARAMETERS: None
DESCRIPTION: The Earth God's interaction set.
*********************************************************************/
int Boss::earthBoss()
{
    if (interacted == false)
    {
        char choice;

        std::cout << "EARTH GOD: \"Ready to battle, mortal?\"\n";

        do
        {
            std::cout << "Y/N: ";
            std::cin >> choice;

            if(choice == 'y' || choice == 'Y')
            {
                if (mainCharacter->getGem(4))//if player has wind gem
                    mainCharacter->setHealthPoints(40);//advantage

                return 1;//fight
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "EARTH GOD: \"Come back when you're ready.\"\n";
                return 9;
            }

        }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
    }
    else if (interacted == true && gemGiven == false)
    {
        if (mainCharacter->getGem(3))
        {
            std::cout << "EARTH GOD: \"It seems you already have an Earth Gem.\"\n";

            gemGiven = true;

            return 0;
        }
        else
        {
            std::cout << "Health replenished and received EARTH GEM.\n";

            gemGiven = true;

            return 3;
        }
    }
    else if (interacted == true && gemGiven == true)
    {
        std::cout << "EARTH GOD: \"I'LL give the goat his money back tomorrow GEEZ LEAVE ME ALONE.\"\n";

        return 0;
    }
}


/*********************************************************************
FUNCTION: int Boss::windBoss()
PARAMETERS: None
DESCRIPTION: The Wind God's interaction set.
*********************************************************************/
int Boss::windBoss()
{
    if (interacted == false)
    {
        char choice;

        std::cout << "WIND GOD: \"You're going to have to fight me for the WIND GEM. Are you ready?\"\n";

        do
        {
            std::cout << "Y/N: ";
            std::cin >> choice;

            if(choice == 'y' || choice == 'Y')
            {
                if (mainCharacter->getGem(2))//if player has fire gem
                    mainCharacter->setHealthPoints(40);//advantage

                return 1;//fight
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "WIND GOD: \"Come back when you're ready.\"\n";

                return 9;//return to map
            }

        }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
    }
    else if (interacted == true && gemGiven == false)
    {
        if (mainCharacter->getGem(4))
        {
            std::cout << "\"Huh, I see you already have a Wind Gem in your possession. Good for you.\"\n";

            gemGiven = true;

            return 0;
        }
        else
        {
            std::cout << "Health replenished and received WIND GEM.\n";

            gemGiven = true;

            return 4;
        }
    }
    else if (interacted == true && gemGiven == true)
    {
        std::cout << "The Wind God stares at you intensely until you leave.\n";

        return 0;
    }
}
