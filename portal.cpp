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
#include "portal.hpp"
#include <iostream>


/*********************************************************************
FUNCTION: Portal::Portal()
PARAMETERS: int
DESCRIPTION: Specifies the type of Portal to make based on the int
received.
*********************************************************************/
Portal::Portal(int pt)
{
    portalType = pt;
}


/*********************************************************************
FUNCTION: interactableType Portal::getInteractableType()
PARAMETERS: None
DESCRIPTION: Returns InteractableType PORTAL.
*********************************************************************/
interactableType Portal::getInteractableType()
{
    return PORTAL;
}


/*********************************************************************
FUNCTION: int Portal::interact()
PARAMETERS: None
DESCRIPTION: Splits off the interaction depending of the type of
portal that was requested.
*********************************************************************/
int Portal::interact()
{
    int choice;

    if (portalType == 1)//1 = water portal
    {
        choice = waterPortal();
    }
    else if (portalType == 2)//2 = fire portal
    {
        choice = firePortal();
    }
    else if (portalType == 3)//3 = earth portal
    {
        choice = earthPortal();
    }
    else if (portalType == 4)//4 = wind portal
    {
        choice = windPortal();
    }
    else if (portalType == 5)//5 = blood portal
    {
        choice = bloodPortal();
    }

    return choice;
}


/*********************************************************************
FUNCTION: int Portal::waterPortal()
PARAMETERS: None
DESCRIPTION: Sending the Player to the Water Temple.
*********************************************************************/
int Portal::waterPortal()
{
    char choice;
    std::cout << "\nThis is the portal to the WATER TEMPLE.\n";

    do
    {
        std::cout << "Step through portal to the WATER TEMPLE? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            return 1;
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 9;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}


/*********************************************************************
FUNCTION: int Portal::firePortal()
PARAMETERS: None
DESCRIPTION: Sending the Player to the Fire Temple.
*********************************************************************/
int Portal::firePortal()
{
    char choice;
    std::cout << "\nThis is the portal to the FIRE TEMPLE.\n";

    do
    {
        std::cout << "Step through portal to the FIRE TEMPLE? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            return 2;
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 9;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}


/*********************************************************************
FUNCTION: int Portal::earthPortal()
PARAMETERS: None
DESCRIPTION: Sending the Player to the Earth Temple.
*********************************************************************/
int Portal::earthPortal()
{
    char choice;
    std::cout << "\nThis is the portal to the EARTH TEMPLE.\n";

    do
    {
        std::cout << "Step through portal to the EARTH TEMPLE? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            return 3;
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 9;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}


/*********************************************************************
FUNCTION: int Portal::windPortal()
PARAMETERS: None
DESCRIPTION: Sending the Player to the Wind Temple.
*********************************************************************/
int Portal::windPortal()
{
    char choice;
    std::cout << "\nThis is the portal to the WIND TEMPLE.\n";

    do
    {
        std::cout << "Step through portal to the WIND TEMPLE? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            return 4;
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 9;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}


/*********************************************************************
FUNCTION: int Portal::bloodPortal()
PARAMETERS: None
DESCRIPTION: Sending the Player to the Wind Temple.
*********************************************************************/
int Portal::bloodPortal()
{
    char choice;
    std::cout << "\nThis is the portal to the BLOOD TEMPLE.\n";

    do
    {
        std::cout << "Step through portal to the BLOOD TEMPLE? Y/N: ";
        std::cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            return 5;
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 9;
        }

    }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
}
