#include "NoRing.h"
#include "Portal.h"
#include "HaveRing.h"
#include "Player.h"

void NoRing::AddRing(Portal* aPortal, Player* aPlayer)
{
	for (int i = 0; i < 2; i++)
	{
		if (aPlayer->GetInventory(i) != NULL and aPlayer->GetInventory(i)->fConsumable==false)
		{
			aPortal->SetPortalRing(aPlayer->GetInventory(i));
			aPortal->SetCurrentState(new HaveRing());
			cout << "\nPortal Message: The ring has been added into the portal\n" << endl;
			return;
		}
	}
	cout << "\nPortal Message: You don't have the ring in your inventory\n" << endl;
}