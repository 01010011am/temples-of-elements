/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "spacelist.hpp"
#include "player.hpp"


/*********************************************************************
CLASS: Game
DESCRIPTION: Controls the game's main menu and sets the game in motion.
*********************************************************************/
class Game
{
    protected:
        Player mainCharacter;
        SpaceList newList;
    public:
        Game();
        void run();
        void objective();
        int play();
        void credits();
        void actionMenu();
        char getAction();
};

#endif // GAME_HPP_INCLUDED
