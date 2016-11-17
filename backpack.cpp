/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "backpack.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: Backpack::Backpack()
PARAMETERS: None
DESCRIPTION: Sets the default array position of the items in backpack
to 0.
*********************************************************************/
Backpack::Backpack()
{
    arrayPosition = 0;

    backpack = new int[4];

    for (int i = 0; i < 4; i++)
    {
        backpack[i] = 0;
    }
}


/*********************************************************************
FUNCTION: Backpack::~Backpack()
PARAMETERS: None
DESCRIPTION: Frees memory
*********************************************************************/
Backpack::~Backpack()
{

    delete [] backpack;

}


/*********************************************************************
FUNCTION: void Backpack::addItem()
PARAMETERS: int
DESCRIPTION: Adding the next item to the list.
*********************************************************************/
void Backpack::addItem(int i)
{
    //adding next item to list
    backpack[arrayPosition++] = i;
}


/*********************************************************************
FUNCTION: bool Backpack::getItem()
PARAMETERS: int
DESCRIPTION: Function returns whether or not the backpack has a certain
gem within it.
*********************************************************************/
bool Backpack::getItem(int gi)
{
    for (int i = 0; i < arrayPosition; i++)
    {
        if (backpack[i] == gi)
        {
            return true;
        }
    }

    return false;
}


/*********************************************************************
FUNCTION: void Backpack::displayList()
PARAMETERS: int
DESCRIPTION: Function displays the contents of the backpack.
*********************************************************************/
void Backpack::displayList()
{
    std::cout << "\nYOUR BACKPACK CONTAINS THE FOLLOWING:\n";

    for (int i = 0; i < arrayPosition; i++)
    {
        if (backpack[i] == 1)
        {
            std::cout << i+1 << ". WATER Gem\n";
        }
        else if (backpack[i] == 2)
        {
            std::cout << i+1 << ". FIRE Gem\n";
        }
        else if (backpack[i] == 3)
        {
            std::cout << i+1 << ". EARTH Gem\n";
        }
        else if (backpack[i] == 4)
        {
            std::cout << i+1 << ". WIND Gem\n";
        }
        else
        {
            std::cout << i << ". SLOT EMPTY.\n";
        }
    }
}
