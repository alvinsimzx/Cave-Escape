#include "CorrectPassword.h"
#include "Portal.h"

void CorrectPassword::AddRing(Portal* aPortal, Player* aPlayer)
{
	cout << "\nPortal Message: The Ring has already been added to the Portal.\n" << endl;
}
void CorrectPassword::EnterPassword(Portal* aPortal, string aUserGuess)
{
	cout << "\nPortal Message: You have already guessed the correct password.\n" << endl;
}

void CorrectPassword::Activate(Portal* aPortal)
{
	aPortal->SetActivated(true);
}
