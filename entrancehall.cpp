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
#include "entrancehall.hpp"
#include "interestpoint.hpp"
#include "portal.hpp"
#include "player.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: EntranceHall::EntranceHall()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
EntranceHall::EntranceHall(Interactable* mainCharacter)
{
    interactableGrid[6][3] = mainCharacter;
    interactableGrid[0][0] = new Portal(1);//water portal
    interactableGrid[0][6] = new Portal(2);//fire portal
    interactableGrid[6][0] = new Portal(3);//earth portal
    interactableGrid[6][6] = new Portal(4);//wind portal
    interactableGrid[3][3] = new InterestPoint(0);//stone mural
}


/*********************************************************************
FUNCTION: EntranceHall::~EntranceHall()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
EntranceHall::~EntranceHall()
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
FUNCTION: spaceType EntranceHall::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns ENTRANCEHALL.
*********************************************************************/
spaceType EntranceHall::getSpaceType()
{
    return ENTRANCEHALL;
}


/*********************************************************************
FUNCTION: void EntranceHall::special()
PARAMETERS: None
DESCRIPTION: EntranceHall's special function.
*********************************************************************/
void EntranceHall::special()
{
    char choice;

    std::cout << "Good morning! Or goodnight? What time is it? Where are you?\n\n";
    do
    {
        std::cout << "You turn on your flashlight... (press Y and enter to continue): ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << "\nIt seems you've woken up in a stone hall. The walls are covered in mildew and\n"
                      << "paintings of battles involving the use of dice. Four things that look like vortexes\n"
                      << "can be found in the four corners of the room. Disoriented and weak from a night of\n"
                      << "cramming to finish your CS 162 Final Project, you summon the strength to get up and\n"
                      << "better observe your surroundings.\n\n"
                      << "Is that a huge stone mural in the middle of the room?\n\n";
            return;
        }

    }while(choice != 'y' || choice != 'Y');
}
