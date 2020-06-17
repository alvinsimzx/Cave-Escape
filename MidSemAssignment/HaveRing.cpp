#include "HaveRing.h"
#include "Portal.h"
#include "CorrectPassword.h"
#include "Player.h"

void HaveRing::AddRing(Portal* aPortal, Player* aPlayer)
{
	cout << "\nPortal Message: The Ring has already been added to the Portal.\n" << endl;
}

void HaveRing::EnterPassword(Portal* aPortal, string aUserGuess)
{
	if (aUserGuess == "echo" && aPortal->GetPortalRing()) //if the player gueses the password correctly and the Portal Ring has been inserted
	{
		cout << "\nPortal Message: Congratulations! You have successfully unlocked the Portal. You may activate it now\n"<<endl;
		aPortal->SetCurrentState(new CorrectPassword());
	}
	else//wrong password but the portal ring has been inserted
	{
		cout << "\nPortal Message: Sorry that was the wrong password\n" << endl;
	}
}

void HaveRing::Activate(Portal* aPortal)
{
	cout << "\nPortal Message: You have not guessed the password\n" << endl;
}