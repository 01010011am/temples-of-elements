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
#include "windspace.hpp"
#include "boss.hpp"
#include "interestpoint.hpp"
#include "player.hpp"
#include "portal.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: WindSpace::WindSpace()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
WindSpace::WindSpace(Interactable* mainCharacter)
{
    interactableGrid[3][0] = mainCharacter;
    interactableGrid[3][3] = new Boss(this->getSpaceType(), mainCharacter);//middle
    interactableGrid[0][0] = new Portal(1);//water portal
    interactableGrid[0][6] = new Portal(2);//fire portal
    interactableGrid[6][0] = new Portal(3);//earth portal
    interactableGrid[6][6] = new Portal(5);//blood portal
}


/*********************************************************************
FUNCTION: WindSpace::~WindSpace()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
WindSpace::~WindSpace()
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
FUNCTION: spaceType WindSpace::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns WINDSPACE.
*********************************************************************/
spaceType WindSpace::getSpaceType()
{
    return WINDSPACE;
}


/*********************************************************************
FUNCTION: void WindSpace::special()
PARAMETERS: None
DESCRIPTION: WindSpace's special function.
*********************************************************************/
void WindSpace::special()
{
    char choice;

    std::cout << "You are teleported to a wooden temple that rests on the side of a grassy knoll. It's\n"
              << "extremely windy here. A hawk screams at you to get your attention as it circles from\n"
              << "way above.\n\n"
              << "HARPY THE HAWK: \"HEY! HEY YOU! HEY!!! HEYYY!!!! HELLOOOO!! UP HERE!!!\" \n\n";
    do
    {
        std::cout << "Ignore the screaming hawk? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << std::endl;
            return;
        }
        else if (choice == 'n' || choice == 'N')
        {
            std::cout << "\nHARPY THE HAWK: \"WIND ONLY FUELS THE FLAMES! IT DOESN'T BLOW THEM OUT! I'M NOT CRAZY!\"\n\n";
            return;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}
