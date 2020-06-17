#pragma once
#include <iostream>

using namespace std;

class Player;
class Portal; //forward declaration to avoid circular dependency

class PortalState
{
public:
	//Use cases that can be override by each state
	virtual void AddRing(Portal* aPortal,Player* aPlayer);
	virtual void Activate(Portal* aPortal);
	virtual void EnterPassword(Portal* aPortal, string aUserGuess);
};

