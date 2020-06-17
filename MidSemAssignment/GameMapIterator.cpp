#include "GameMapIterator.h"

GameMapIterator::GameMapIterator(GameMap* aGameMap)
{
	fGameMap = aGameMap;
}

GameMapIterator::~GameMapIterator() {}

string GameMapIterator::operator*() const
{
	return fGameMap->GetGameMessage();
}

GameMapIterator& GameMapIterator::operator++()
{
	if (fGameMap->GetNextForward() != NULL)
	{
		fGameMap = fGameMap->GetNextForward();
	}
	return *this;
}

GameMapIterator& GameMapIterator::operator++(int)
{
	GameMapIterator temp = *this;
	++(*this);
	return temp;
}

GameMapIterator& GameMapIterator::operator--()
{
	if (fGameMap->GetPreviousBack() != NULL)
	{
		fGameMap = fGameMap->GetPreviousBack();
	}
	return *this;
}

GameMapIterator& GameMapIterator::operator--(int)
{
	GameMapIterator temp = *this;
	--(*this);

	return temp;
}


bool GameMapIterator::operator==(const Iterator& aOther) const
{
	return(fGameMap == aOther.fGameMap);
}
bool GameMapIterator::operator!=(const Iterator& aOther) const
{
	return !(fGameMap == aOther.fGameMap);
}

GameMapIterator GameMapIterator::begin()
{
	GameMapIterator ltemp = *this;
	while (ltemp.fGameMap->GetPreviousBack() != NULL)
	{
		ltemp--;
	}
	return ltemp;

}

GameMap* GameMapIterator::current() const //returns the current GameMap node being pointed at
{
	return fGameMap;
}

GameMapIterator GameMapIterator::end()
{
	GameMapIterator temp = *this;
	while (temp.fGameMap->GetNextForward() != NULL)
	{
		temp++;
	}
	return temp;
}