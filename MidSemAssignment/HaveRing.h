#pragma once
#include "PortalState.h"
class HaveRing: public PortalState
{
public:
	//Override the use cases
	void AddRing(Portal* aPortal, Player* aPlayer);
	void EnterPassword(Portal* aPortal, string aUserGuess);
	void Activate(Portal* aPortal);
};

