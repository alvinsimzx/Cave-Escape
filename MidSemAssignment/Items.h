#pragma once
#include <iostream>
#include "ItemsArr.h"
using namespace std;

template <class T>
class Items : public ItemsArr
{
private:
	T fSpecialValues;
	string fName;
public:
	Items()
	{
		fName = "";
		fConsumable = false;
	}
	Items(string aName,bool aConsumable, T aSpecialvalue)
	{
		fName = aName;
		fConsumable = aConsumable;
		fSpecialValues = aSpecialvalue;
	};

	~Items() {};

	const T& GetSpecialValues()
	{
		return fSpecialValues;
	}
	void showName()
	{
		cout<< fName;
	}
	
};

