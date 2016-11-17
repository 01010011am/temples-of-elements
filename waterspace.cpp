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
#include "waterspace.hpp"
#include "boss.hpp"
#include "interestpoint.hpp"
#include "player.hpp"
#include "portal.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: WaterSpace::WaterSpace()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
WaterSpace::WaterSpace(Interactable* mainCharacter)
{
    interactableGrid[3][0] = mainCharacter;
    interactableGrid[3][3] = new Boss(this->getSpaceType(), mainCharacter);//middle
    interactableGrid[0][0] = new Portal(2);//fire portal
    interactableGrid[0][6] = new Portal(3);//earth portal
    interactableGrid[6][0] = new Portal(4);//wind portal
    interactableGrid[6][6] = new Portal(5);//blood portal
}


/*********************************************************************
FUNCTION: WaterSpace::~WaterSpace()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
WaterSpace::~WaterSpace()
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
FUNCTION: spaceType WaterSpace::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns WATERSPACE.
*********************************************************************/
spaceType WaterSpace::getSpaceType()
{
    return WATERSPACE;
}


/*********************************************************************
FUNCTION: void WaterSpace::special()
PARAMETERS: None
DESCRIPTION: WaterSpace's special function.
*********************************************************************/
void WaterSpace::special()
{
    char choice;

    std::cout << "You are teleported to a white marble temple surrounded by, you guessed it--water.\n"
              << "Y'know what? It's actually pretty nice here. A chance dolphin swims up to the edge\n"
              << "where the water meets the temple. It looks like it wants to talk to you.\n\n";
    do
    {
        std::cout << "Engage the dolphin in casual conversation? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << "\nCHANCE THE DOLPHIN: \"Good day!\"\n"
                      << "YOU: \"Uh, hi?\"\n"
                      << "CHANCE THE DOLPHIN: \"Too much of THIS turns water into mud. Bye!\"\n"
                      << "YOU: \"???\"\n\n";
            return;
        }
        else if (choice == 'n' || choice == 'N')
        {
            std::cout << std::endl;
            return;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}

