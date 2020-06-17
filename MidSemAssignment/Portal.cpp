#include "Portal.h"
#include "PortalState.h"
#include "NoRing.h"
#include "Player.h"

Portal::Portal()
{
	fPortalRing = NULL;
	fActivated = false;
	fPortalState = new NoRing();
}

Portal::~Portal(){}

void Portal::SetCurrentState(PortalState* aPortalState) //Set the current state of the portal
{
	if (fPortalState)
	{
		delete fPortalState;
		fPortalState = NULL;
	}
	fPortalState = aPortalState;
}

void Portal::SetPortalRing(ItemsArr* aPortalRing) //add the Portal Ring
{
	fPortalRing = aPortalRing;
	
}

void Portal::SetActivated(bool aActivated) //Activate the portal
{
	fActivated = aActivated;
}

bool Portal::GetPortalRing() //checks if the portal ring is in the portal
{
	if (fPortalRing)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Portal::GetActivated() //checks if the portal is activated
{
	return fActivated;
}

void Portal::AddRing(Player* aPlayer) //Adds a portal ring to the portal
{
	if (fPortalState)
	{
		fPortalState->AddRing(this,aPlayer);
	}
};

void Portal::Activate() //Activates the portal
{
	if (fPortalState)
	{
		fPortalState->Activate(this);
	}
};
void Portal::EnterPassword(string aUserGuess) //Guess the portal's password
{
	if (fPortalState)
	{
		fPortalState->EnterPassword(this,aUserGuess);
	}
}