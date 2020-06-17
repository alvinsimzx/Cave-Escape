#include "GameMap.h"

GameMap::GameMap()
{
	fPreviousBack = NULL;
	fMonster = false;
	fItem = false;
	fNextForward = NULL;
	fGameMessage = "";
	fWeaponDropped = NULL;

}

GameMap::GameMap(bool aMonsterAvailable, bool aItemAvailable, string aGameMessage,  Weapons* aWeaponDropped)
{
	fMonster = aMonsterAvailable;
	fItem = aItemAvailable;
	fGameMessage = aGameMessage;
	fNextForward = NULL;
	fPreviousBack = NULL;
	fWeaponDropped = aWeaponDropped;
}

GameMap::~GameMap()
{}


bool GameMap::GetMonster()
{
	return fMonster;
}
bool GameMap::GetItem()
{
	return fItem;
}

GameMap* GameMap::GetNextForward()
{
	return fNextForward;
}
GameMap* GameMap::GetPreviousBack()
{
	return fPreviousBack;
}
string GameMap::GetGameMessage()
{
	return fGameMessage;
}
Weapons* GameMap::GetWeaponDropped()
{
	return fWeaponDropped;
}

void GameMap::SetMonster(bool aMonsterAvailable)
{
	fMonster = aMonsterAvailable;
}
void GameMap::SetItem(bool aItemAvailable)
{
	fItem = aItemAvailable;
}
void GameMap::SetGameMessage(string aMessage)
{
	fGameMessage = aMessage;
}

void GameMap::SetNextForward(GameMap* aNext)
{
	aNext->fPreviousBack = this;
	if (fNextForward != NULL)
	{
		aNext->fNextForward = fNextForward;
		fNextForward->fPreviousBack = aNext;
	}
	fNextForward = aNext;
}
void GameMap::SetPreviousBack(GameMap* aBack)
{
	aBack->fNextForward = this;
	if (fPreviousBack != NULL)
	{
		aBack->fPreviousBack = fPreviousBack;
		fPreviousBack->fNextForward = aBack;
	}
	fPreviousBack = aBack;
}
void GameMap::SetWeaponDropped(Weapons* aWeapon)
{
	fWeaponDropped = aWeapon;
}