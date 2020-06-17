#pragma once
#include <iostream>
#include "Items.h"
#include "Clues.h"
#include <stack>
using namespace std;

class Monsters
{
private:
	int fDamage;
	bool fHasItems;
	bool fHaveClue;
public:
	Monsters(int aDamage,bool aHasItems,bool aHaveClue);
	~Monsters();

	virtual void MonsterMessage();//polymorphic function

	//Getters
	int DamageDealt();
	bool HasItem();
	bool HasClue();

};
