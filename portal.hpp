/*********************************************************************
TITLE: Temples Of Elements
AUTHOR: Samantha Manubay
DATE: 8/04/16
DESCRIPTION: Text-based game where the player moves through several
spaces of different types in an effort to accomplish some goal. Use
good Object Oriented Programming style including inheritance,
polymorphism, and pointers.
*********************************************************************/


#ifndef PORTAL_HPP_INCLUDED
#define PORTAL_HPP_INCLUDED
#include "interactable.hpp"


/*********************************************************************
CLASS: Portal
DESCRIPTION: Portals transport the Player to various spaces within the
temple.  Portal is a subclass of Interactable.
*********************************************************************/
class Portal: public Interactable
{
    protected:
        int portalType;
    public:
        Portal(int);
        virtual interactableType getInteractableType();
        virtual int interact();
        virtual int attack() {}
        virtual void defend(int) {}
        virtual void giveGem(int) {}
        virtual bool getGem(int) {}
        virtual void displayGems() {}
        int entrancePortal();
        int waterPortal();
        int firePortal();
        int earthPortal();
        int windPortal();
        int bloodPortal();
};

#endif // PORTAL_HPP_INCLUDED
