#include "Weapons.h"

Weapons::Weapons()
{
	fName = "";
	fWeaponHealth = 0;
}

Weapons::~Weapons(){}

Weapons::Weapons(string aName, int aWeaponHealth)
{
	fName = aName;
	fWeaponHealth = aWeaponHealth;
};
void Weapons::KillMonster()
{
	if (fWeaponHealth == 0) //if the Weapon is broken
	{
		cout << "Your " + fName + " is broken and could not attack monsters. " << endl;
	}
	else
	{
		cout << "You attacked the monster. " << endl;
		--fWeaponHealth;
	}

};
int Weapons::GetWeaponHealth()
{
	return fWeaponHealth;
};

string Weapons::GetWeaponName()
{
	return fName;
}
