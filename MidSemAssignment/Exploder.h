#pragma once
#include "Monsters.h"
class Exploder:public Monsters
{
public:
	Exploder(int aDamage, bool aHasItems, bool aHaveClue);
	~Exploder();
	
	//Overrided MonsterMessage()
	void MonsterMessage();	
};

