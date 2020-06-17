#include "Clues.h"

Clues::Clues()
{
	fMessage = "";
}

Clues::Clues(string aMessage)
{
	fMessage = aMessage;
}

Clues* Clues::NextClue()
{
	return fNextClue;
}

Clues* Clues::LatestClue()
{
	Clues* TempClue = this;
	while (TempClue->fNextClue!=NULL)
	{
		TempClue = fNextClue;
	}
	return TempClue;
}

void Clues::SetNextClue(Clues* aNextClue)
{

	if (fNextClue != NULL)
	{
		aNextClue->fNextClue = fNextClue;
	}
	fNextClue = aNextClue;
}


void Clues::SetTail(Clues* aNextClue)
{	
	LatestClue()->SetNextClue(aNextClue);
}

string Clues::ShowMessage()
{
	return fMessage;
}

Clues::~Clues()
{}