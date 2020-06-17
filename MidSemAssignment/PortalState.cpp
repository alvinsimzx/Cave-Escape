#include "PortalState.h"
#include "Portal.h"

void PortalState::AddRing(Portal* aPortal,Player* aPlayer)
{
	cout << "\nPortal Message: You don't have any ring to put in.\n" << endl;
}
void PortalState::Activate(Portal* aPortal)
{
	cout << "\nPortal Message: The portal has no ring and the password is not entered. Therfore, it cannot be activated.\n" << endl;
}
void PortalState::EnterPassword(Portal* aPortal, string aUserGuess)
{
	cout << "\nPortal Message: There is no ring in the portal\n" << endl;
}