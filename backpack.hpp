/*********************************************************************
TITLE: Final Project
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef BACKPACK_HPP_INCLUDED
#define BACKPACK_HPP_INCLUDED
#include "backpack.hpp"


/*********************************************************************
CLASS: Backpack
DESCRIPTION: Backpack is responsible for holding the player's gems.
Backpack has a capacity of 4 items.
*********************************************************************/
class Backpack
{
    private:
        int* backpack;
        int arrayPosition;
    public:
        Backpack();
        ~Backpack();
        void addItem(int);
        bool getItem(int);
        void displayList();
};

#endif // BACKPACK_HPP_INCLUDED
