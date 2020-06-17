#pragma once
#include "Monsters.h"

class Witch :public Monsters
{
public:
	Witch(int aDamage, bool aHasItems, bool aHaveClue);
	~Witch();

	//Overrided MonsterMessage()
	void MonsterMessage();
};
