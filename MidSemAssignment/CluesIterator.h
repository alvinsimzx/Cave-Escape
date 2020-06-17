#pragma once
#include "Clues.h"
class CluesIterator
{
private:
	Clues* fClues;
public:
	typedef CluesIterator Iterator;
	CluesIterator();
	CluesIterator(Clues* aClues);
	~CluesIterator();

	string operator*() const;

	//incremental operator overload
	CluesIterator& operator++();
	CluesIterator& operator++(int);

	//equivalence operator overload
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;
	
	CluesIterator end();
};


