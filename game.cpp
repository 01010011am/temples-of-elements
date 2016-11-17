/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#include "game.hpp"
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <iostream>


/*********************************************************************
FUNCTION: Game::Game()
PARAMETERS: None
DESCRIPTION: Default constructor--adds the first 5 space/nodes in the
game.
*********************************************************************/
Game::Game()
{
    newList.add(1, &mainCharacter);//waterspace
    newList.add(2, &mainCharacter);//firespace
    newList.add(3, &mainCharacter);//earthspace
    newList.add(4, &mainCharacter);//windspace
    srand(time(NULL));//for random numbers
}


/*********************************************************************
FUNCTION: void Game::run()
PARAMETERS: None
DESCRIPTION: This function displays the main menu and allows the user
to initiate the game.
*********************************************************************/
void Game::run()
{
    int choice;

    do
    {
        std::cout << "\n******** THE TEMPLES OF ELEMENTS: MAIN MENU ********\n\n";
        std::cout << "1. OBJECTIVE\n";
        std::cout << "2. PLAY\n";
        std::cout << "3. CREDITS\n";
        std::cout << "4. QUIT\n\n";
        std::cout << "What would you like to do? ";
        std::cout << "Choice: ";
        std::cin >> choice;

        while(std::cin.fail() || (choice < 1) || (choice > 4))
        {
            std::cout << "Invalid entry. What would you like to do?: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }

        if(choice == 1)
        {
            objective();
        }
        else if(choice == 2)
        {
            choice = play();
        }
        else if(choice == 3)
        {
            credits();
        }

    }while(choice != 4);
}


/*********************************************************************
FUNCTION: void Game::objective()
PARAMETERS: None
DESCRIPTION: Describes the main objective of the game to the user.
*********************************************************************/
void Game::objective()
{
    std::cout << "\n\n****************** GAME OBJECTIVE ******************\n\n";
    std::cout << "The object of THE TEMPLES OF ELEMENTS is to gather elemental gems\n"
              << "to aid you, the player, in defeating various elemental temple gods.\n"
              << "After defeating a temple god, the god will bestow upon you one of\n"
              << "their elemental gems which you will absolutely NEED to defeat\n"
              << "another god, and so on. Each elemental god has a weakness. For\n"
              << "example, the FIRE GOD is weak against a carrier of the WATER GEM.\n"
              << "You get your first elemental gem from the STONE MURAL in the middle\n"
              << "of the ENTRANCE HALL. The kind of stone you get from the stone\n"
              << "mural is random and may vary every time you play the game. Each of\n"
              << "the four portal pointers located in every space (except for the 6th\n"
              << "and last stage), will teleport you to an elemental temple, and each\n"
              << "space will offer you a clue. After you leave the ENTRANCE HALL, that\n"
              << "space node is deleted as you can never go back to it. After you\n"
              << "have collected all 4 of the elemental gems, you will have access to\n"
              << "the BLOOD TEMPLE, and the node for that space will be added. If you\n"
              << "do not have all 4 elemental gems and you attempt to move through\n"
              << "the BLOOD PORTAL, will you be redirected to any of the other 4\n"
              << "available temples. Lastly, a poisonous air permeates each temple\n"
              << "and spending too much time in any ONE temple (approximately 25\n"
              << "steps or moves per temple) will cause you to die. To interact with\n"
              << "objects in the game, attempt to move into the space they occupy.\n\n";
}


/*********************************************************************
FUNCTION: void Game::play()
PARAMETERS: None
DESCRIPTION: This function runs the main processes of the game.
*********************************************************************/
int Game::play()
{
    char action;
    int teleport;

    newList.add(0, &mainCharacter);//entrancehall

    do
    {
        std::cout << "\n\n******************* ENTRANCE HALL *******************\n\n";

        if (newList.getSpace(0)->beenHere == false)//if player has never been here before
        {
            newList.getSpace(0)->special();//the space's special function

            newList.getSpace(0)->beenHere = true;//setting to true so it doesn't repeat
        }

        newList.getSpace(0)->display();//displays the space

        actionMenu();

        std::cout << "ACTION: ";

        std::cin >> action;

        teleport = newList.getSpace(0)->move(action);//do user's action

    }while(teleport == 9);

    newList.remove(0);//removing the entrance hall because you can never go back

    do
    {
        if(teleport == 1)
        {
            do
            {
                std::cout << "\n\n******************* WATER TEMPLE *******************\n\n";

                if (newList.getSpace(1)->beenHere == false)
                {
                    newList.getSpace(1)->special();
                    newList.getSpace(1)->beenHere = true;
                }

                newList.getSpace(1)->display();

                actionMenu();

                std::cout << "ACTION: ";

                std::cin >> action;

                teleport = newList.getSpace(1)->move(action);

            }while(teleport == 9);
        }
        else if(teleport == 2)
        {
            do
            {
                std::cout << "\n\n******************** FIRE TEMPLE *******************\n\n";

                if (newList.getSpace(2)->beenHere == false)
                {
                    newList.getSpace(2)->special();
                    newList.getSpace(2)->beenHere = true;
                }

                newList.getSpace(2)->display();

                actionMenu();

                std::cout << "ACTION: ";

                std::cin >> action;

                teleport = newList.getSpace(2)->move(action);

            }while(teleport == 9);
        }
        else if(teleport == 3)
        {
            do
            {
                std::cout << "\n\n******************* EARTH TEMPLE *******************\n\n";

                if (newList.getSpace(3)->beenHere == false)
                {
                    newList.getSpace(3)->special();
                    newList.getSpace(3)->beenHere = true;
                }

                newList.getSpace(3)->display();

                actionMenu();

                std::cout << "ACTION: ";

                std::cin >> action;

                teleport = newList.getSpace(3)->move(action);

            }while(teleport == 9);
        }
        else if(teleport == 4)
        {
            do
            {
                std::cout << "\n\n******************** WIND TEMPLE *******************\n\n";

                if (newList.getSpace(4)->beenHere == false)
                {
                    newList.getSpace(4)->special();
                    newList.getSpace(4)->beenHere = true;
                }

                newList.getSpace(4)->display();

                actionMenu();

                std::cout << "ACTION: ";

                std::cin >> action;

                teleport = newList.getSpace(4)->move(action);

            }while(teleport == 9);
        }
        else if(teleport == 5)
        {
            //if you have all the gems...
            if (mainCharacter.getGem(1) &&//water gem
                mainCharacter.getGem(2) &&//fire gem
                mainCharacter.getGem(3) &&//earth gem
                mainCharacter.getGem(4))//wind gem
            {
                //adding a space during run time because player has what it take to access it
                newList.add(5, &mainCharacter);

                do
                {
                    std::cout << "\n\n******************* BLOOD TEMPLE *******************\n\n";

                    if (newList.getSpace(5)->beenHere == false)
                    {
                        newList.getSpace(5)->special();
                        newList.getSpace(5)->beenHere = true;
                    }

                    newList.getSpace(5)->display();

                    actionMenu();

                    std::cout << "ACTION: ";

                    std::cin >> action;

                    teleport = newList.getSpace(5)->move(action);

                }while(teleport == 9);
            }
            else//if you don't have all the gems yet you get sent to a random temple
            {
                std::cout << "\nYou step through the portal and come out the other side...\n";
                std::cout << "... but wait, this isn't the Blood Temple?\n";
                teleport = rand() % (4 - 1 + 1) + 1;//sending player to random space in temple
            }
        }

    }while(teleport > 0 && teleport < 6);

    if (teleport == 0)
        return 4;
}


/*********************************************************************
FUNCTION: void Game::actionMenu()
PARAMETERS: None
DESCRIPTION: Displays the in-game action menu
*********************************************************************/
void Game::actionMenu()
{
    std::cout << "\nAVAILABLE ACTIONS (type character then press enter):\n";
    std::cout << "W = UP | S = DOWN | A = LEFT | D = RIGHT\n";
    std::cout << "B = LOOK INSIDE BACKPACK\n";
}


/*********************************************************************
FUNCTION: void Game::credits()
PARAMETERS: None
DESCRIPTION: Credits section.
*********************************************************************/
void Game::credits()
{
    std::cout << "\n\n********************** CREDITS *********************\n\n";
    std::cout << "AUTHOR: Samantha Manubay\n";
    std::cout << "DATE: 08/07/2016\n";
    std::cout << "DESCRIPTION: Design and implement a text-based game using inheritance,\n";
    std::cout << "polymorphism, and pointers. The player must move through a series of \n";
    std::cout << "rooms or compartments to gather items to achieve some purpose.\n\n";
}
