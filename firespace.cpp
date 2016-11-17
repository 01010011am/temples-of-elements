/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "space.hpp"
#include "firespace.hpp"
#include "boss.hpp"
#include "interestpoint.hpp"
#include "player.hpp"
#include "portal.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: FireSpace::FireSpace()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
FireSpace::FireSpace(Interactable* mainCharacter)
{
    interactableGrid[3][0] = mainCharacter;
    interactableGrid[3][3] = new Boss(this->getSpaceType(), mainCharacter);//middle
    interactableGrid[0][0] = new Portal(1);//water portal
    interactableGrid[0][6] = new Portal(3);//earth portal
    interactableGrid[6][0] = new Portal(4);//wind portal
    interactableGrid[6][6] = new Portal(5);//blood portal
}


/*********************************************************************
FUNCTION: FireSpace::~FireSpace()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
FireSpace::~FireSpace()
{
    for(int i = 0; i < SPACESIZE; i++)
    {
        for(int j = 0; j < SPACESIZE; j++)
        {
            interactableGrid[i][j] = NULL;
            delete interactableGrid[i][j];
        }
    }
}


/*********************************************************************
FUNCTION: spaceType FireSpace::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns FIRESPACE.
*********************************************************************/
spaceType FireSpace::getSpaceType()
{
    return FIRESPACE;
}


/*********************************************************************
FUNCTION: void FireSpace::special()
PARAMETERS: None
DESCRIPTION: FireSpace's special function.
*********************************************************************/
void FireSpace::special()
{
    char choice;

    std::cout << "You are teleported to a black granite temple surrounded by flowing lava and random\n"
              << "eruptions of fire. It's ridiculously hot and you're sweating bullets, which is\n"
              << "pretty gross if you think about it in the literal sense. Imagine? Anywho, You notice a\n"
              << "fluorescent sign hanging on one of the temple's majestic columns, but you can't read\n"
              << "it because the light switch for the sign is off.\n\n";
    do
    {
        std::cout << "Turn the sign on? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << "\n\"WATER GEM CARRIERS NOT WELCOME HERE\" the sign reads.\n\n";

            return;
        }
        else if (choice == 'n' || choice == 'N')
        {
            std::cout << std::endl;
            return;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}
