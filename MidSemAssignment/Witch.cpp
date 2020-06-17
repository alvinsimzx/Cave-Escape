#include "Witch.h"
Witch::Witch(int aDamage, bool aHasItems, bool aHaveClue) : Monsters(aDamage, aHasItems, aHaveClue){}
Witch::~Witch(){}

void Witch::MonsterMessage()
{
	if (this->DamageDealt() >= 5)
	{
		cout << "A SUPER WITCH has appeared and it is about throw a potion at you!\nBEWARE! THIS WILL DEAL EXTRA DAMAGE THAN A NORMAL WITCH" << endl;
	}
	else
	{
		cout << "A Wtich has appeared and it is about throw a potion at you!" << endl;
	}
	
}