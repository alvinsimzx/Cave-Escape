#pragma once
#include "Monsters.h"
#include "Weapons.h"

/*
Implementation on Doubly Linked List
*/

class GameMap
{
private:
	//Values
	bool fMonster;
	bool fItem;
	string fGameMessage;
	Weapons* fWeaponDropped;

	//Next and Previous pointers
	GameMap* fNextForward;
	GameMap* fPreviousBack;

	
public:
	//Default constructor
	GameMap();
	GameMap(bool aMonsterAvailable, bool aItemAvailable, string aGameMessage, Weapons* aWeaponDropped);//overloaded constructor
	~GameMap();

	//Getters
	bool GetMonster();
	bool GetItem();
	string GetGameMessage();
	Weapons* GetWeaponDropped();

	//Setters
	void SetMonster(bool aMonsterAvailable);
	void SetItem(bool aItemAvailable);
	void SetGameMessage(string aMessage);
	void SetWeaponDropped(Weapons* aWeapon);

	//Node Setter and Getters
	void SetNextForward(GameMap* aNext); // append
	void SetPreviousBack(GameMap* aBack);// prepend
	GameMap* GetNextForward();
	GameMap* GetPreviousBack();
	
};


