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
#include "interestpoint.hpp"
#include "spacelist.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>


/*********************************************************************
FUNCTION: InterestPoint::InterestPoint()
PARAMETERS: None
DESCRIPTION: Sets interest point type.
*********************************************************************/
InterestPoint::InterestPoint(int i)
{
    interestPointType = i;
    srand(time(NULL));//for random numbers
}


/*********************************************************************
FUNCTION: interactableType InterestPoint::getInteractableType()
PARAMETERS: None
DESCRIPTION: Return's the Interactable's intertactableType, which in
this case is INTERESTPOINT.
*********************************************************************/
interactableType InterestPoint::getInteractableType()
{
    return INTERESTPOINT;
}


/*********************************************************************
FUNCTION: int InterestPoint::interact()
PARAMETERS: None
DESCRIPTION: Initiate's the possible interactions w702-248-0660ith an InterestPoint
object. Depending on space type, InterestPoint may behave differently.
*********************************************************************/
int InterestPoint::interact()
{
    if (interestPointType == 0)
    {
        return stoneMural();//stone mural returns starter gem
    }
    else if (interestPointType == 7)
    {
        exitGem();
        return 7;
    }
}


/*********************************************************************
FUNCTION: void InterestPoint::stoneMural()
PARAMETERS: None
DESCRIPTION: Initiate's the interactions with the stone mural.
*********************************************************************/
int InterestPoint::stoneMural()
{
    if(interacted == false)
    {
        std::cout << "\n\nYup, it's a huge stone mural in the middle of the room. Complete with a bunch of\n"
                  << "rudimentary symbols doodled on it in... crayon? You look closer and observe what\n"
                  << "appears to be THREE distinct images representative of the elements EARTH, WIND, and\n"
                  << "FIRE. On an unrelated note, the song \"September\" starts playing in your head. You\n"
                  << "walk around the mural. You find another painting but it's obscured by dust. You\n"
                  << "attempt to wipe away said dust.\n\n"
                  << "Whoa, the huge stone mural just collapsed on itself! As you gaze at the pile of\n"
                  << "rubble and bemoan the mural's poor craftsmanship, you notice something sparkly\n"
                  << "amongst the debris. Naturally, you pick it up and stick it in your backpack.\n\n"
                  << "To check out your backpack's contents, press B!\n";

        interacted = true;//setting interacted to true so dialogue doesn't repeat

        return (rand() % (4 - 1 + 1) + 1);//return a random gem
    }
    else
    {
        std::cout << "\nJust a bunch of rubble where the stone mural once stood. Miserable craftsmanship...\n";

        return 0;//return nothing
    }
}


/*********************************************************************
FUNCTION: void InterestPoint::exitGem()
PARAMETERS: None
DESCRIPTION: Player has defeated the puzzle.
*********************************************************************/
void InterestPoint::exitGem()
{
    std::cout << "\nReceived EXIT GEM!\n\n"
              << "Well how about that? As soon as you grasp the EXIT GEM in your hands, you are\n"
              << "conveniently teleported back home to comfortable safety and the game ends.\n\n"
              << "Thank you for playing! :)\n\n";
}
