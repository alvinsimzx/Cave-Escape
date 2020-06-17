#include "Exploder.h"

Exploder::Exploder(int aDamage, bool aHasItems, bool aHaveClue) :Monsters(aDamage, aHasItems, aHaveClue){}
Exploder::~Exploder(){}

void Exploder::MonsterMessage()
{
	if (this->DamageDealt() >= 5)
	{
		cout << "A VOLATILE EXPLODER has appeared and it is about to explode!\nBEWARE! THIS WILL DEAL EXTRA DAMAGE THAN A NORMAL EXPLODER" << endl;
	}
	else
	{
		cout << "An Exploder has appeared and it is about to explode!" << endl;
	}
}