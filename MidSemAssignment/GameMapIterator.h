#pragma once
#include "GameMap.h"
class GameMapIterator
{
private:
	GameMap* fGameMap;
public:
	typedef GameMapIterator Iterator;
	GameMapIterator(GameMap* aGameMap);
	~GameMapIterator();
	
	string operator*() const;

	//Incremental operators
	GameMapIterator& operator++();
	GameMapIterator& operator++(int);

	//Decremental Operators
	GameMapIterator& operator--();
	GameMapIterator& operator--(int);

	//equivalence operators
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;

	GameMapIterator begin();
	GameMap* current() const;// points and returns the current node
	GameMapIterator end();
  };

