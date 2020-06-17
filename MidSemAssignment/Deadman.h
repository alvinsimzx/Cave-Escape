#pragma once
#include "Monsters.h"
class Deadman:public Monsters
{
public:
	Deadman(int aDamage, bool aHasItems, bool aHaveClue);//Constructor
	~Deadman();
};

