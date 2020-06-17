#pragma once
#include "PortalState.h"

class Portal;
class NoRing : public PortalState
{
public:
	//Override Add Ring Use Case
	void AddRing(Portal* aPortal, Player* aPlayer);
};


