#pragma once
#include <iostream>
#include "Weapons.h"
#include <string>
#include "GameMapIterator.h"
#include "Items.h"
#include "CluesIterator.h"
using namespace std;

class Portal;
class Player
{
private:
	int fPlayerHealth;
	string fPlayerName;
	ItemsArr* fPlayerInventory[2];
	Weapons* fPlayerWeapon;
	Clues* fCluesFound;
public:
	Player(string aPlayerName, int aPlayerHealth);
	
	//Getters
	int GetPlayerHealth();
	string GetPlayerName();
	string GetCurrentWeaponName();
	int GetCurrentWeaponHealth();
	ItemsArr* GetInventory(int aIndex);
	Weapons* GetPlayerWeapon();

	//Map Movement methods
	GameMapIterator& DeterminePlayerMovement(GameMapIterator& aGameMapIterator);
	GameMapIterator& MoveForward(GameMapIterator& aGameMapIterator);
	GameMapIterator& MoveBack(GameMapIterator& aGameMapIterator);

	//Player action methods
	void ShowPlayerInfo(GameMapIterator aGameMapIter);
	bool AttackMonster(Monsters* aMonster);
	void GetItems(Monsters * aMonster, ItemsArr * aitem);
	void GetNewClues(Clues* aClue);
	void Eatfood();
	void TakeWeapon(GameMap* aGameMap);
	void DisposeWeapon();
	void DisposeItem();
	void UsePortal(GameMapIterator& aGameMapIterator, Portal* aGamePortal);
	
	//Determine Player Actions
	void DeterminePlayerActions(GameMapIterator& aGameMapIterator, Portal* aGamePortal);
	
	~Player();
	};

