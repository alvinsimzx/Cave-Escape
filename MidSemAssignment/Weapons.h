#pragma once
#include <iostream>
using namespace std;
class Weapons
{
private:
	string fName;
	int fWeaponHealth;
public:
	Weapons();
	Weapons(string aName, int aWeaponHealth);
	~Weapons();
	
	//Getter
	int GetWeaponHealth();
	string GetWeaponName();
	
	//Weapon Actions
	void KillMonster();
};

