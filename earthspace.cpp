/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "space.hpp"
#include "earthspace.hpp"
#include "boss.hpp"
#include "interestpoint.hpp"
#include "player.hpp"
#include "portal.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: EarthSpace::EarthSpace()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
EarthSpace::EarthSpace(Interactable* mainCharacter)
{
    interactableGrid[3][0] = mainCharacter;
    interactableGrid[3][3] = new Boss(this->getSpaceType(), mainCharacter);//middle
    interactableGrid[0][0] = new Portal(1);//water portal
    interactableGrid[0][6] = new Portal(2);//fire portal
    interactableGrid[6][0] = new Portal(4);//wind portal
    interactableGrid[6][6] = new Portal(5);//blood portal
}


/*********************************************************************
FUNCTION: EarthSpace::~EarthSpace()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
EarthSpace::~EarthSpace()
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
FUNCTION: spaceType EarthSpace::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns EARTHSPACE.
*********************************************************************/
spaceType EarthSpace::getSpaceType()
{
    return EARTHSPACE;
}


/*********************************************************************
FUNCTION: void EarthSpace::special()
PARAMETERS: None
DESCRIPTION: EarthSpace's special function.
*********************************************************************/
void EarthSpace::special()
{
    char choice;

    std::cout << "You are teleported to a stone temple on the top of a tall rocky mountain. Nothing up\n"
              << "here but you, the EARTH GOD at the center of the temple, and that irritated looking\n"
              << "goat over there. The goat beckons you to come closer to it.\n\n";
    do
    {
        std::cout << "Go see what the goat wants? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << "\nBILLY THE GOAT: \"Want to know a secret?\"\n"
                      << "YOU: \"Sure.\"\n"
                      << "BILLY THE GOAT: \"The EARTH GOD hates WIND.\"\n"
                      << "YOU: \"Oh thanks. Why are you telling me this?\"\n"
                      << "BILLY THE GOAT: \"The EARTH GOD needed some money to pay for this hair removal\n"
                      << "procedure on his back a few weeks ago so I lent him some cash and he hasn't paid me\n"
                      << "back yet.\"\n\n";
            return;
        }
        else if (choice == 'n' || choice == 'N')
        {
            std::cout << std::endl;
            return;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}
