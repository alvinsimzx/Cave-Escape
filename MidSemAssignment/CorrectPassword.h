#pragma once
#include "PortalState.h"
class CorrectPassword : public PortalState
{
	//Overrided Use Case
	void Activate(Portal* aPortal);
	void AddRing(Portal* aPortal, Player* aPlayer);
	void EnterPassword(Portal* aPortal, string aUserGuess);
};

