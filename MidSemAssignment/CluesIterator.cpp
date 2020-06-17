#include "CluesIterator.h"

CluesIterator::CluesIterator()
{
	fClues = NULL;
}
CluesIterator::~CluesIterator() {}

CluesIterator::CluesIterator(Clues* aClues)
{
	fClues = aClues;
};

string CluesIterator::operator*() const
{
	return fClues->ShowMessage();
}

CluesIterator& CluesIterator::operator++()
{
	if (fClues->NextClue() != NULL)//will only return clues that have a value
	{
		fClues = fClues->NextClue();
	}
	return *this;
};

CluesIterator& CluesIterator::operator++(int)//postfix
{
	CluesIterator ltemp = *this;
	++(*this);
	return ltemp;
};

bool CluesIterator::operator==(const Iterator& aOther) const
{
	return(fClues == aOther.fClues);
}
bool CluesIterator::operator!=(const Iterator& aOther) const
{
	return !(fClues == aOther.fClues);
}

CluesIterator CluesIterator::end()
{
	CluesIterator ltemp = *this;
	while (ltemp.fClues->NextClue() != NULL)
	{
		ltemp++;
	}
	return ltemp;
};