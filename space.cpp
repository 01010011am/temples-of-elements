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
#include <iostream>


/*********************************************************************
FUNCTION: Space::Space()
PARAMETERS: None
DESCRIPTION: Filling interactable array with NULL to start things off.
Also setting stepsTillPoisoned to 0 to start and beenHere to false so
the special function doesn't get repeated more than once.
*********************************************************************/
Space::Space()
{
    stepsTillPoisoned = 0;
    beenHere = false;

    //filling interactable array with NULL
    for(int i = 0; i < SPACESIZE; i++)
    {
        for(int j = 0; j < SPACESIZE; j++)
        {
            interactableGrid[i][j] = NULL;
        }
    }
}


/*********************************************************************
FUNCTION: Space::~Space()
PARAMETERS: None
DESCRIPTION: Freeing up memory
*********************************************************************/
Space::~Space()
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
FUNCTION: void Space::display()
PARAMETERS: None
DESCRIPTION: Displaying the character array.
*********************************************************************/
void Space::display()
{
    //printing out the grid
    for(int i = 0; i < SPACESIZE; i++)
    {
        for(int j = 0; j < SPACESIZE; j++)
        {
            if (interactableGrid[i][j] == NULL)
            {
                std::cout << " . ";
            }
            else if (interactableGrid[i][j]->getInteractableType() == PLAYER)
            {
                std::cout << " M ";
            }
            else if (interactableGrid[i][j]->getInteractableType() == BOSS)
            {
                std::cout << " G ";
            }
            else if (interactableGrid[i][j]->getInteractableType() == INTERESTPOINT)
            {
                std::cout << " ! ";
            }
            else if (interactableGrid[i][j]->getInteractableType() == PORTAL)
            {
                std::cout << " P ";
            }
        }
        std::cout << std::endl;
    }
}


/*********************************************************************
FUNCTION: void Space::move()
PARAMETERS: char
DESCRIPTION: Accepts user input in the form of char and translates
information into a move/interaction.
*********************************************************************/
int Space::move(char m)
{
    if (stepsTillPoisoned == POISONED)
    {
        std::cout << "\n\nOh snap, you died! Apparently a poisonous gas saturates the temple and you breathed\n";
        std::cout << "too much of it in. Woops! Maybe you shouldn't spend too much time in any one\n";
        std::cout << "particular space...\n";
        return 0;
    }

    stepsTillPoisoned++;//increment every time you move

    for (int i = 0; i < SPACESIZE; i++)
    {
        for (int j = 0; j < SPACESIZE; j++)
        {
            if (interactableGrid[i][j] != NULL
            && interactableGrid[i][j]->getInteractableType() == PLAYER
            && (interactableGrid[i][j]->getMoved()) == false)
            {

                if(m == 'b' || m == 'B')
                {
                    interactableGrid[i][j]->displayGems();
                }

                //if the space Player wants to move to is empty
                if ((m == 'a' || m == 'A')//left
                && (j > 0)
                && interactableGrid[i][j - 1] == NULL)
                {
                    interactableGrid[i][j - 1] = interactableGrid[i][j];
                    interactableGrid[i][j - 1]->setMoved(true);
                    interactableGrid[i][j] = NULL;
                    clearMoved();
                    return 9;
                }
                else if ((m == 'd' || m == 'D')//right
                && (j < SPACESIZE - 1)
                && interactableGrid[i][j + 1] == NULL)
                {
                    interactableGrid[i][j + 1] = interactableGrid[i][j];
                    interactableGrid[i][j + 1]->setMoved(true);
                    interactableGrid[i][j] = NULL;
                    clearMoved();
                    return 9;
                }
                else if ((m == 'w' || m == 'W')//up
                && (i > 0)
                && interactableGrid[i - 1][j] == NULL)
                {
                    interactableGrid[i - 1][j] = interactableGrid[i][j];
                    interactableGrid[i - 1][j]->setMoved(true);
                    interactableGrid[i][j] = NULL;
                    clearMoved();
                    return 9;
                }
                else if ((m == 's' || m == 'S')//down
                && (i < SPACESIZE - 1)
                && interactableGrid[i + 1][j] == NULL )
                {
                    interactableGrid[i + 1][j] = interactableGrid[i][j];
                    interactableGrid[i + 1][j]->setMoved(true);
                    interactableGrid[i][j] = NULL;
                    clearMoved();
                    return 9;
                }


                //if player is interacting with another Interactable
                int gem = 0;

                if ((m == 'a' || m == 'A')//left
                && (j > 0)
                && ((interactableGrid[i][j - 1]->getInteractableType() == BOSS)
                || (interactableGrid[i][j - 1]->getInteractableType() == INTERESTPOINT)
                || (interactableGrid[i][j - 1]->getInteractableType() == PORTAL)))
                {

                    if (interactableGrid[i][j - 1]->getInteractableType() == PORTAL)//go through portal
                    {
                        return interactableGrid[i][j - 1]->interact();//send user through PORTAL
                    }
                    else if (interactableGrid[i][j - 1]->getInteractableType() == BOSS)//battle time
                    {
                        int fight = 1;

                        //if you've never fought this boss before
                        if (interactableGrid[i][j - 1]->getInteracted() == false)
                        {
                            //asks the user if they're ready to fight. 1 = ready, 0 = not ready
                            fight = interactableGrid[i][j - 1]->interact();

                            while (fight == 1)//if ready to fight
                            {
                                //0 = game over, 8 = user wins
                                fight = battle(interactableGrid[i][j], interactableGrid[i][j - 1]);
                            }

                            if(fight == 8)//if user wins
                            {
                                //reset player's health points
                                interactableGrid[i][j]->setHealthPoints(8);

                                //set interacted to true so you don't fight him again
                                interactableGrid[i][j - 1]->setInteracted(true);

                                //get new interaction now that the boss/god has been defeated
                                gem = interactableGrid[i][j - 1]->interact();

                                if (gem != 0)//if not equal to 0, player got a gem
                                {
                                    interactableGrid[i][j]->giveGem(gem);//give player the gem
                                }

                                return 9;//return to space
                            }

                            return fight;//game over
                        }
                        else
                        {
                            //boss/god will tell you to leave him alone if you try interacting again
                            interactableGrid[i][j - 1]->interact();
                        }
                    }
                    else//interest point interaction
                    {
                        gem = interactableGrid[i][j - 1]->interact();

                            if (gem > 0 && gem < 5)//if not equal to 0, player got a gem
                            {
                                interactableGrid[i][j]->giveGem(gem);//give player the gem
                            }
                            else if (gem == 7)
                            {
                                return 0;
                            }

                        return 9;
                    }
                }
                else if ((m == 'd' || m == 'D')//right
                && (j < SPACESIZE - 1)
                && ((interactableGrid[i][j + 1]->getInteractableType() == BOSS)
                || (interactableGrid[i][j + 1]->getInteractableType() == INTERESTPOINT)
                || (interactableGrid[i][j + 1]->getInteractableType() == PORTAL)))
                {
                    if (interactableGrid[i][j + 1]->getInteractableType() == PORTAL)
                    {
                        return interactableGrid[i][j + 1]->interact();
                    }
                    else if (interactableGrid[i][j + 1]->getInteractableType() == BOSS)//battle time
                    {
                        int fight = 1;

                        //if you've never fought this boss before
                        if (interactableGrid[i][j + 1]->getInteracted() == false)
                        {
                            //asks the user if they're ready to fight. 1 = ready, 0 = not ready
                            fight = interactableGrid[i][j + 1]->interact();

                            while (fight == 1)//if ready to fight
                            {
                                //0 = game over, 8 = user wins
                                fight = battle(interactableGrid[i][j], interactableGrid[i][j + 1]);
                            }

                            if(fight == 8)//if user wins
                            {
                                //reset player's health points
                                interactableGrid[i][j]->setHealthPoints(8);

                                //set interacted to true so you don't fight him again
                                interactableGrid[i][j + 1]->setInteracted(true);

                                //get new interaction now that the boss/god has been defeated
                                gem = interactableGrid[i][j + 1]->interact();

                                if (gem != 0)//if not equal to 0, player got a gem
                                {
                                    interactableGrid[i][j]->giveGem(gem);//give player the gem
                                }

                                return 9;//return to space
                            }

                            return fight;//game over
                        }
                        else
                        {
                            //boss/god will tell you to leave him alone if you try interacting again
                            interactableGrid[i][j + 1]->interact();
                        }
                    }
                    else//interest point interaction
                    {
                        gem = interactableGrid[i][j + 1]->interact();

                            if (gem > 0 && gem < 5)//if not equal to 0, player got a gem
                            {
                                interactableGrid[i][j]->giveGem(gem);//give player the gem
                            }
                            else if (gem == 7)
                            {
                                return 0;
                            }

                        return 9;
                    }
                }
                else if ((m == 'w' || m == 'W')//up
                && (i > 0)
                && ((interactableGrid[i - 1][j]->getInteractableType() == BOSS)
                || (interactableGrid[i - 1][j]->getInteractableType() == INTERESTPOINT)
                || (interactableGrid[i - 1][j]->getInteractableType() == PORTAL)))
                {
                    if (interactableGrid[i - 1][j]->getInteractableType() == PORTAL)
                    {
                        return interactableGrid[i - 1][j]->interact();
                    }
                    else if (interactableGrid[i - 1][j]->getInteractableType() == BOSS)//battle time
                    {
                        int fight = 1;

                        //if you've never fought this boss before
                        if (interactableGrid[i - 1][j]->getInteracted() == false)
                        {
                            //asks the user if they're ready to fight. 1 = ready, 0 = not ready
                            fight = interactableGrid[i - 1][j]->interact();

                            while (fight == 1)//if ready to fight
                            {
                                //0 = game over, 8 = user wins
                                fight = battle(interactableGrid[i][j], interactableGrid[i - 1][j]);
                            }

                            if(fight == 8)//if user wins
                            {
                                //reset player's health points
                                interactableGrid[i][j]->setHealthPoints(8);

                                //set interacted to true so you don't fight him again
                                interactableGrid[i - 1][j]->setInteracted(true);

                                //get new interaction now that the boss/god has been defeated
                                gem = interactableGrid[i - 1][j]->interact();

                                if (gem != 0)//if not equal to 0, player got a gem
                                {
                                    interactableGrid[i][j]->giveGem(gem);//give player the gem
                                }

                                return 9;//return to space
                            }

                            return fight;//game over
                        }
                        else
                        {
                            //boss/god will tell you to leave him alone if you try interacting again
                            interactableGrid[i - 1][j]->interact();
                        }
                    }
                    else
                    {
                        gem = interactableGrid[i - 1][j]->interact();

                            if (gem > 0 && gem < 5)//if not equal to 0, player got a gem
                            {
                                interactableGrid[i][j]->giveGem(gem);//give player the gem
                            }
                            else if (gem == 7)
                            {
                                return 0;
                            }

                        return 9;
                    }
                }
                else if ((m == 's' || m == 'S')//down
                && (i < SPACESIZE - 1)
                && ((interactableGrid[i + 1][j]->getInteractableType() == BOSS)
                || (interactableGrid[i + 1][j]->getInteractableType() == INTERESTPOINT)
                || (interactableGrid[i + 1][j]->getInteractableType() == PORTAL)))
                {
                    if (interactableGrid[i + 1][j]->getInteractableType() == PORTAL)
                    {
                        return interactableGrid[i + 1][j]->interact();
                    }
                    else if (interactableGrid[i + 1][j]->getInteractableType() == BOSS)//battle time
                    {
                        int fight = 1;

                        //if you've never fought this boss before
                        if (interactableGrid[i + 1][j]->getInteracted() == false)
                        {
                            //asks the user if they're ready to fight. 1 = ready, 0 = not ready
                            fight = interactableGrid[i + 1][j]->interact();

                            while (fight == 1)//if ready to fight
                            {
                                //0 = game over, 8 = user wins
                                fight = battle(interactableGrid[i][j], interactableGrid[i + 1][j]);
                            }

                            if(fight == 8)//if user wins
                            {
                                //reset player's health points
                                interactableGrid[i][j]->setHealthPoints(8);

                                //set interacted to true so you don't fight him again
                                interactableGrid[i + 1][j]->setInteracted(true);

                                //get new interaction now that the boss/god has been defeated
                                gem = interactableGrid[i + 1][j]->interact();

                                if (gem != 0)//if not equal to 0, player got a gem
                                {
                                    interactableGrid[i][j]->giveGem(gem);//give player the gem
                                }

                                return 9;//return to space
                            }

                            return fight;//game over
                        }
                        else
                        {
                            //boss/god will tell you to leave him alone if you try interacting again
                            interactableGrid[i + 1][j]->interact();
                        }
                    }
                    else
                    {
                        gem = interactableGrid[i + 1][j]->interact();

                            if (gem > 0 && gem < 5)//if not equal to 0, player got a gem
                            {
                                interactableGrid[i][j]->giveGem(gem);//give player the gem
                            }
                            else if (gem == 7)
                            {
                                return 0;
                            }

                        return 9;
                    }
                }
                else//if you hit a wall
                {
                    return 9;
                }
            }
        }
    }
    return 9;
}


/*********************************************************************
FUNCTION: int battle();
PARAMETERS: Interactable*, Interactable*
DESCRIPTION: This is the battle function containing the attack and
defend sequence.
*********************************************************************/
int Space::battle(Interactable* maincharacter, Interactable* templeGod)
{
    int attackPoints = 0;

    attackPoints = maincharacter->attack();//Player attack

    templeGod->defend(attackPoints);//Temple God defend

    //checking to see if Temple God fainted
    if (templeGod->getHealthPoints() <= 0)
    {
        std::cout << "\n\n * * * THE TEMPLE GOD WAS DEFEATED! * * * \n\n";
        return 8;//continue with temple exploration
    }

    attackPoints = templeGod->attack();//Temple God attack

    maincharacter->defend(attackPoints);//Player defend

    //checking to see if Player's a goner
    if (maincharacter->getHealthPoints() <= 0)
    {
        std::cout << "Aw, you died. Try again!\n\n";
        std::cout << "\n\n * * * GAME OVER * * * \n\n";
        return 0;//end game
    }

    std::cout << std::endl;

    return 1;//no one defeated, continue the battle
}


/*********************************************************************
FUNCTION: void Space::clearMoved()
PARAMETERS: None
DESCRIPTION: Resets the Player's moved bool to false so Player can
move again.
*********************************************************************/
void Space::clearMoved()
{
    for (int i = 0; i < SPACESIZE; i++)
    {
        for (int j = 0; j < SPACESIZE; j++)
        {
            if (interactableGrid[i][j] != NULL)
            {
               interactableGrid[i][j]->setMoved(false);
            }
        }
    }
}
