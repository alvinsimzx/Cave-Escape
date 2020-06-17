#pragma once
#include <iostream>
#include "Items.h"
using namespace std;

class PortalState;
class Player;
class Portal
{
protected:
	PortalState* fPortalState;
	ItemsArr* fPortalRing;
	bool fActivated;
public:
	Portal();
	~Portal();
	//Setters
	void SetCurrentState(PortalState* aPortalState);
	void SetPortalRing(ItemsArr* aPortalRing);
	void SetActivated(bool aActivated);

	//Getters
	bool GetPortalRing();
	bool GetActivated();

	//Use Cases
	void AddRing(Player* aPlayer);
	void Activate();
	void EnterPassword(string aUserGuess);
};