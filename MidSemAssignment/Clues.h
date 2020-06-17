#pragma once
#include <iostream>
using namespace std;
class Clues
{
private:
	string fMessage;//Values
	Clues* fNextClue;//Next Pointer

public:
	Clues();
	Clues(string aMessage);
	~Clues();
	
	//Getter
	Clues* NextClue();
	Clues* LatestClue();// Tail of Linked List

	//Setter
	void SetNextClue(Clues* aNextClue);// Set the next clue from the current
	void SetTail(Clues* aNextClue);// Set the tail of the linked list

	//Return the Clues's content
	string ShowMessage();
};

