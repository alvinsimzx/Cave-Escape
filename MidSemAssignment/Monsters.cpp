#include "Monsters.h"

Monsters::Monsters(int aDamage, bool aHasItems, bool aHaveClue)
{
	fDamage = aDamage;
	fHasItems = aHasItems;
	fHaveClue = aHaveClue;
};

Monsters::~Monsters()
{}

void Monsters::MonsterMessage()
{
	cout<< "OH NO! A Monster has appeared"<<endl;
}

int Monsters::DamageDealt()
{
	return fDamage;
}

bool Monsters::HasItem()
{
	return fHasItems;
};

bool Monsters::HasClue()
{
	return fHaveClue;
};
