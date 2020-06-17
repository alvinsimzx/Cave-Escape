#include "Player.h"
#include "Portal.h"

Player::Player(string aPlayerName, int aPlayerHealth)
{
	fPlayerName = aPlayerName;
	fPlayerHealth = aPlayerHealth;
	fPlayerWeapon = NULL;
	fPlayerInventory[0] = NULL;
	fPlayerInventory[1] = NULL;
	fCluesFound = new Clues();
};

//Getters
int Player::GetPlayerHealth()
{
	return fPlayerHealth;
};

string Player::GetPlayerName()
{
	return fPlayerName;
};

string Player::GetCurrentWeaponName()
{
	return fPlayerWeapon->GetWeaponName();
}

int Player::GetCurrentWeaponHealth()
{
	return fPlayerWeapon->GetWeaponHealth();
}

ItemsArr* Player::GetInventory(int aIndex)
{
	return fPlayerInventory[aIndex];
}

Weapons* Player::GetPlayerWeapon()
{
	return fPlayerWeapon;
}

GameMapIterator& Player::DeterminePlayerMovement(GameMapIterator& aGameMapIterator)
{
	
	char lplayermove = NULL;
	if (aGameMapIterator == aGameMapIterator.end()) //The player can only move back if they reached the end of the game map
	{
		cout << "Where would you like to move?\n>> A. Move to the previous cave" << endl;
		cout << "Please enter a move" << endl;
		while (lplayermove != 'a')
		{
			cout << "Please enter a move: ";
			cin >> lplayermove;
			lplayermove = tolower(lplayermove);
		}

		return MoveBack(aGameMapIterator);
	}
	else if (aGameMapIterator == aGameMapIterator.begin()) //The player can only move forward if they are at the start of the game map
	{
		cout << "Where would you like to move?\n>> A. Move to the next cave" << endl;
		while (lplayermove != 'a')
		{
			cout << "Please enter a move: ";
			cin >> lplayermove;
			lplayermove = tolower(lplayermove);
		}
		return MoveForward(aGameMapIterator);
	}
	else //When the player are anywhere between the start and the end
	{
		cout << "Where would you like to move?\n>> A.Move to the next cave\n>> B.Move to the previous cave" << endl;
		cin >> lplayermove;
		lplayermove = tolower(lplayermove);
		while (true)
		{
			if (lplayermove == 'a')
			{
				return MoveForward(aGameMapIterator);
			}
			else if (lplayermove == 'b')
			{
				return MoveBack(aGameMapIterator);
			}
			else
			{
				cout << "Please Try again" << endl;
				cin >> lplayermove;
				lplayermove = tolower(lplayermove);
			}
		}
	}
}

//Changes the Iterator based on the Cave that each player moves into
GameMapIterator& Player::MoveForward(GameMapIterator& aGameMapIterator)
{
	aGameMapIterator++;
	return aGameMapIterator;
};
GameMapIterator& Player::MoveBack(GameMapIterator& aGameMapIterator)
{
	aGameMapIterator--;
	return aGameMapIterator;
};

//Display Header for main game
void Player::ShowPlayerInfo(GameMapIterator aGameMapIter)
{
	system("cls");
	cout << "Player Name: " + fPlayerName << endl; //Player's name information
	cout << "=============================================================================================" << endl;
	cout << "Your Current Health: " << fPlayerHealth; //Player's health information
	
	//Weapon information will change if or if not they have a weapon with them
	if (fPlayerWeapon == NULL)
	{
		cout << "\t\tYour current Weapon: NONE|" << endl;
	}
	else
	{
		cout << "|\tYour Current Weapon: " << fPlayerWeapon->GetWeaponName() << "|\tWeapon Health: " << fPlayerWeapon->GetWeaponHealth() << endl;
	}

	//Inventory information
	cout << "Your Inventory (2 items maximum) : ";;
	for (int i = 0; i < 2; i++)
	{

		if (fPlayerInventory[i] == NULL)
		{
			continue;
		}
		else
		{
			fPlayerInventory[i]->showName();
			cout << "  ";
		}
	}

	CluesIterator lCluesIter(fCluesFound);
	//Show all the clues they have collected so far for the password
	cout << "\nClues collected for PORTAL's password:" << endl;
	for (lCluesIter; lCluesIter != lCluesIter.end(); lCluesIter++)
	{
		cout << *lCluesIter << endl;
	}
	cout << *lCluesIter << endl;
	cout << "" << endl;

	//Indicates the current situation of the cave they are in
	cout << "\nCurrent Situation: " << *aGameMapIter << endl;
	cout << "=============================================================================================" << endl;

}

bool Player::AttackMonster(Monsters* aMonster) //based on the situation, a boolean value is returned whether or not they have killed the monster
{
	if (fPlayerWeapon == NULL) //if they don't have a weapon, they will be forced to take damage
	{
		cout << "You don't have any usable weapons in hand." << endl;
		cout << "You cannot attack the monster and thus, you've taken some damage" << endl;
		fPlayerHealth = fPlayerHealth - (aMonster->DamageDealt());
		return false;
	}
	else if (fPlayerWeapon->GetWeaponHealth() <= 0)//if their weapon is broken, they will be forced to take damage
	{
		cout << "Your weapon is broken and can't be used." << endl;
		cout << "You cannot attack the monster and thus, you've taken some damage" << endl;
		fPlayerHealth = fPlayerHealth - (aMonster->DamageDealt());
		return false;
	}
	else{ //When they have a weapon and the weapon is usable
		char lUserInput;
		cout << "Would you like to attack the monster? Y/N" << endl;
		cin >> lUserInput;
		if (tolower(lUserInput) == 'y')
		{
			fPlayerWeapon->KillMonster();
			return true;
		}
		else
		{
			cout << "You decided to not attack the monster and you've taken some damage" << endl;
			fPlayerHealth = fPlayerHealth - (aMonster->DamageDealt());
			return false;
		}

	}

};

void Player::GetItems(Monsters* aMonster, ItemsArr* aitem)
{
	if (aMonster->HasItem()) //If the monster drops an item
	{
		if (fPlayerInventory[0] != NULL && fPlayerInventory[1] != NULL) //if their inventory is full
		{
			cout << "Your inventory is full and the item can't be picked up" << endl;
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				if (fPlayerInventory[i] == NULL)//checking which inventory slot is empty
				{
					fPlayerInventory[i] = aitem;
					cout << "The Monster dropped an Item and it has been added into your Inventory" << endl;
					break;
				}
			}
		}
		
	}
}

void Player::GetNewClues(Clues* aClue)
{
	
	if (fCluesFound->ShowMessage() == "")
	{
		fCluesFound = aClue;
	}
	else 
	{
		fCluesFound->SetTail(aClue);
	}
}

void Player::Eatfood() //Eating food is only possible if the player has collected food
{
	for (int i = 0; i < 2; i++)
	{
		if (fPlayerInventory[i] == NULL)
		{
			continue;
		}
		else if (fPlayerInventory[i]->fConsumable && fPlayerHealth < 10) //if the item is a type of food and the player's health is low
		{
			fPlayerHealth = fPlayerHealth + static_cast<Items<int>*>(fPlayerInventory[i])->GetSpecialValues();
			fPlayerInventory[i] = NULL;
			return;
		}
		else if (fPlayerHealth == 10)
		{
			cout << "Your can't eat your food now because your health is full" << endl;
			return;
		}
	}
	cout << "You don't have any food in your inventory" << endl;

};


void Player::TakeWeapon(GameMap* aGameMap)
{
	char lResponse;
	cout << "Would you like to pick up this " + aGameMap->GetWeaponDropped()->GetWeaponName() + " ? Y/N" << endl;
	cin >> lResponse;
	if (tolower(lResponse) == 'y')//if the player wants to pickup that weapon
	{
		fPlayerWeapon = aGameMap->GetWeaponDropped();
		aGameMap->SetWeaponDropped(NULL);
		aGameMap->SetGameMessage("Nothing to be seen so far, there used to be a weapon here but you've already picked it");
	}
	else
	{
		cout << "You decided not to pickup this weapon" << endl;
	}

}

void Player::DisposeWeapon()
{
	if (fPlayerWeapon == NULL) //If the player does not a weapon initially
	{
		cout << "You do not have any weapon to dispose" << endl;
	}
	else
	{
		cout << "You have disposed your weapon" << endl;
		fPlayerWeapon = NULL;
	}
}

void Player::DisposeItem()
{
	if (fPlayerInventory[0] == NULL && fPlayerInventory[1] == NULL) //if their inventory is empty
	{
		cout << "You do not have any items to dispose" << endl;
	}
	else
	{
		int lUserChoice;
		cout << "Which item do you want to dispose?" << endl;
		for (int i = 0; i < 2; i++)
		{
			if (fPlayerInventory[i] != NULL)
			{
				cout << i + 1<<". ";
				fPlayerInventory[i]->showName();
				cout << "" << endl;
			}
		}
		cout << "Enter your choice based on the number:";
		cin >> lUserChoice;
		lUserChoice -= 1; //get the actual index value

		if (lUserChoice > 2 || lUserChoice < 0 || fPlayerInventory[lUserChoice] == NULL)
		{
			cout << "There is no item at that location. Please try again." << endl;
		}
		else
		{
			fPlayerInventory[lUserChoice] = NULL;
		}
	}
	
}


void Player::DeterminePlayerActions(GameMapIterator& aGameMapIterator,Portal* aGamePortal)
{
	
	int luserChoice = 0;
	while (luserChoice!=5)
	{
		cout << "What would you like to do at this location?" << endl;
		cout << ">> 1. Use Portal\n>> 2. Eat Food\n>> 3. Dispose your weapon\n>> 4. Dispose your item\n>> 5. Make a move" << endl;
		cin >> luserChoice;

		if (luserChoice == 1) // Chooses to use the portal (only available at the first cave)
		{
			UsePortal(aGameMapIterator, aGamePortal);
			if (aGamePortal->GetActivated())
			{
				break;
			}
		}
		else if (luserChoice == 2) //Chooses to Eat Food
		{
			Eatfood();
		}
		else if (luserChoice == 3) //Chooses to dispose their weapon
		{
			DisposeWeapon();
		}
		else if (luserChoice == 4) //Chooses to dispose their item
		{
			DisposeItem();
		}
		else if (luserChoice == 5) //Wants to move to another cave
		{
			return;
		}
		else // Invalid choice
		{
			cout << "That is not a valid choice, please try again" << endl;
		}
		cin.clear();
		cin.ignore();
	}
	
	
	
}

void Player::UsePortal(GameMapIterator& aGameMapIterator, Portal* aGamePortal)
{
	if (aGameMapIterator == aGameMapIterator.begin())//checks if the player is at the start of the map
	{
		char UserResponse;
		cout << "What would you like to do with the portal?\n>> A. Add Portal Ring\n>> B. Enter Password\n>> C. Activate\n>> D. Nothing" << endl;
		cin >> UserResponse;
		if (tolower(UserResponse) == 'a')// Add Portal Ring
		{
			aGamePortal->AddRing(this);
		}
		else if (tolower(UserResponse) == 'b')// Guess the Password
		{
				string lPasswordGuess;
				cout << "What's your password guess? " << endl;
				cin >> lPasswordGuess;
				aGamePortal->EnterPassword(lPasswordGuess);

		}
		else if (tolower(UserResponse) == 'c')//Activate the portal
		{
			aGamePortal->Activate();
		}else{ //Do Nothing
			return;}
	}
	else// if the player is not at the start of the map
	{
		cout << "There is no Portal here, you need to go back to the starting point" << endl;
	}
}

Player::~Player()
{}