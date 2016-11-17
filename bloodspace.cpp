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
#include "bloodspace.hpp"
#include "interestpoint.hpp"
#include "player.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: BloodSpace::BloodSpace()
PARAMETERS: Interactable*
DESCRIPTION: Places the Interactables in the grid.
*********************************************************************/
BloodSpace::BloodSpace(Interactable* mainCharacter)
{
    interactableGrid[6][3] = mainCharacter;
    interactableGrid[3][3] = new InterestPoint(7);//the end
}


/*********************************************************************
FUNCTION: BloodSpace::~BloodSpace()
PARAMETERS: None
DESCRIPTION: Frees memory.
*********************************************************************/
BloodSpace::~BloodSpace()
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
FUNCTION: spaceType BloodSpace::getSpaceType()
PARAMETERS: None
DESCRIPTION: Returns the spaceType of the space, in this case the
function returns BLOODSPACE.
*********************************************************************/
spaceType BloodSpace::getSpaceType()
{
    return BLOODSPACE;
}


/*********************************************************************
FUNCTION: void BloodSpace::special()
PARAMETERS: None
DESCRIPTION: BloodSpace's special function.
*********************************************************************/
void BloodSpace::special()
{
    char choice;

    std::cout << "Wait, what's this? You are teleported to a plain white room with a very tiny note\n"
              << "taped onto one of the walls.\n\n";
    do
    {
        std::cout << "Read coffee-stained note on the wall? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            std::cout << "\"Greetings! The Blood Temple is undergoing heavy renovations at this time. The Blood\n"
                      << "God also called in sick this morning due to a nasty cold so unfortunately there will\n"
                      << "be no final boss battle. THE TEMPLES OF ELEMENTS Management apologizes for any\n"
                      << "inconveniences this might cause. On the bright side, congratulations on not dying!\"\n"
                      << "Well, okay then.\n\n"
                      << "There's something on top of a small, uneven table in the center of the room. Better\n"
                      << "Check it out.\n\n";
            return;
        }
        else if (choice == 'n' || choice == 'N')
        {
            std::cout << "There's something on top of a small, uneven table in the center of the room. Better\n"
                      << "Check it out.\n\n";
            return;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}

