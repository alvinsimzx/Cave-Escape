// MidSemAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <windows.h>
#include "Player.h"
#include "Deadman.h"
#include "Monsters.h"
#include "Deadman.h"
#include "Witch.h"
#include "Exploder.h"
#include "Clues.h"
#include "Portal.h"
#include "CluesIterator.h"
#include "Stack.h"

int main()
{
    //Intialise Game Clues and put them in a stack
    // The answer is "echo"
    Clues* FirstClue = new Clues("- It has 4 letters.");
    Clues* SecondClue = new Clues("- It speaks without a mouth and hears without an ear.");
    Clues* ThirdClue = new Clues("- It has no body, but comes alive with wind.");
    Clues* FourthClue = new Clues("- It can be created easily in an empty room.");
 
    Stack<Clues*> lClueStack(4);
    lClueStack.push(FirstClue);
    lClueStack.push(SecondClue);
    lClueStack.push(ThirdClue);
    lClueStack.push(FourthClue);

    //Intialise Game Weapons and put them in a stack
    Stack<Weapons*> lWeaponsStack(2);
    lWeaponsStack.push(new Weapons("Wooden Sword", 2));
    lWeaponsStack.push(new Weapons("Iron Sword", 5));
    
    //Intialise Game Items and put them in a stack
    Stack<ItemsArr*> lItemsStack(6);
    lItemsStack.push(new Items<string>("Ring", false, "This is the needed ring"));
    lItemsStack.push(new Items<int>("Cheese", true, 3));
    lItemsStack.push(new Items<string>("Ring", false, "This is the needed ring"));
    lItemsStack.push(new Items<int>("Pizza", true, 4));
    lItemsStack.push(new Items<string>("Ring", false, "This is the needed ring"));
    lItemsStack.push(new Items<int>("Apple", true, 2));

    //Intialise Game Monsters and put them in a stack
    Stack<Monsters*> lMonsterStack(8);
    lMonsterStack.push(new Witch(4, false,true));
    lMonsterStack.push(new Exploder(3, true,false));
    lMonsterStack.push(new Witch(6, true, false));
    lMonsterStack.push(new Deadman(2, true,true));
    lMonsterStack.push(new Exploder(5, true, true));
    lMonsterStack.push(new Witch(4, true,false));
    lMonsterStack.push(new Deadman(2, false,true));
    lMonsterStack.push(new Exploder(3, true,false));

    //Initialise intial spawn
    GameMap* spawn = new GameMap(false,false, "You are at the start of the cave and the portal is here.",NULL);


    //Initialising the Game Map
    GameMap* tempMap = spawn;// temporary storage for current GameMap

    for (int i = 1; i < 16; i++)
    {
        if ((i==4) || (i==7) || (i==13) || (i==9) ||(i==11)) //These locations will indicate they are monster zones
        {
            tempMap->SetNextForward(new GameMap(true, true, "YOU'VE ENTERED A MONSTER ZONE!", NULL));
            tempMap = tempMap->GetNextForward();
        }
        else if (i==2 || i==14)// Locations with weapons on the floor
        {
            tempMap->SetNextForward(new GameMap(false, false, "Nothing to be seen so far but there is a weapon on the floor,", lWeaponsStack.top()));
            tempMap = tempMap->GetNextForward();
            lWeaponsStack.pop();
        }
        else
        {
            string lMessage = "\nYou have entered cave No." + to_string(i + 1) + ",\nNothing to be seen so far.";
            tempMap->SetNextForward(new GameMap(false, false, lMessage, NULL));
            tempMap = tempMap->GetNextForward();
        }
       
    }
    //Main Program Start
    cout <<R"(

  ___   __   _  _  ____    ____  ____   ___   __   ____  ____ 
 / __) / _\ / )( \(  __)  (  __)/ ___) / __) / _\ (  _ \(  __)
( (__ /    \\ \/ / ) _)    ) _) \___ \( (__ /    \ ) __/ ) _) 
 \___)\_/\_/ \__/ (____)  (____)(____/ \___)\_/\_/(__)  (____)

)"<<'\n';

    //Get Player's Name
    char lPlayerName[500];
    cout << "Please enter your name: ";
    cin.getline(lPlayerName,500);

    //Creates the Player Instance
    Player* player1 = new Player(lPlayerName, 10);
    system("cls");

    // Creates the GameMapIterator
    GameMapIterator iter(spawn);

    //Node to represent the current gamemap the player is in
    GameMap* lCurrentNode = iter.current();
    
    //Node to represent the Latest Clue
    Clues* tempClues = new Clues();

    //Creates the Game Portal
    Portal* GamePortal = new Portal();

    //Initial Story Line Below
    cout << "You may press the ENTER key to skip this message\n" << endl;
    cout << "Game Story:" << endl;

    string GameInitialMessage = "Welcome " + player1->GetPlayerName() +"!\nYou've found yourself in a random cave and you don't know how you got here.\nYou get up and you realised there is a machine on your right. It says the word \"PORTAL\" and from the instructions at the side, it tells you that you need to obtain a certain ring to unlock the portal. However, that's not all. \nThere is also a 4 letter password that you need to key in to activate the portal fully.\nThe ring is located in the cave and you need to retrieve it along with the clues to the word!";
    cout << GameInitialMessage << endl;
   
    cout << "" << endl;
    system("pause");
    system("cls");

    //Main Game Loop
    while (true)// The game will only stop when the player has successfully activated the portal
    {
        bool lPlayerAttackedMonster;//Check if the monster was attacked

            //Clues Iterator Instance
            player1->ShowPlayerInfo(iter);//Show Player Information at the top

            // the monster will spawn if the current node has monsters and the Game Monster stack is not empty
            if (lCurrentNode->GetMonster() && !(lMonsterStack.isEmpty()))
            {
                lMonsterStack.top()->MonsterMessage();
                lPlayerAttackedMonster = player1->AttackMonster(lMonsterStack.top());
                /*
                Players can only get items if the following requirements are met:
                - Monster was killed
                - Monster had items
                - The Game Items stack is not empty
                */
                if (!(lMonsterStack.isEmpty()) && lMonsterStack.top()->HasItem() && lPlayerAttackedMonster)
                {
                    player1->GetItems(lMonsterStack.top(), lItemsStack.top());
                    lItemsStack.pop();//remove an item from the stack
                }
                /*
                Players can only get clues if the following requirements are met:
                - Monster was killed
                - Monster had clues
                - The Game Clues stack is not empty
                */
                if (!(lClueStack.isEmpty()) && lMonsterStack.top()->HasClue() && lPlayerAttackedMonster)
                {
                    cout << "\nYou got a clue from this monster and it reads:" << endl;
                    cout << lClueStack.top()->ShowMessage() << endl;
                    cout << "\n" << endl;
                    player1->GetNewClues(lClueStack.top());
                    lClueStack.pop();//remove a clue from the stack
                }
                lMonsterStack.pop();//remove a monster from the stack
            }
            else if (lCurrentNode->GetWeaponDropped()!=NULL) //if the current node has a weapon
            {
                player1->TakeWeapon(lCurrentNode);
            }
            if (player1->GetPlayerHealth() <= 0) // if the player's health is 0 or below, the game is over
            {
                break;
            }
            player1->DeterminePlayerActions(iter,GamePortal);//Determine self actions the players want to take

            if (GamePortal->GetActivated())//checks if the portal has been activated already
            {
                break;
            }
            player1->ShowPlayerInfo(iter);
            iter = player1->DeterminePlayerMovement(iter);//Determine the player's next step in moving around the caves
            
            lCurrentNode = iter.current();//change the current cave the player is in     
        }

    system("cls");
    if (GamePortal->GetActivated())
    {
        cout << "Congratulations " + player1->GetPlayerName() + "!\nYou have successfully escaped the cave and gone back to safe lands.\nSee you next time in the next adventure!" << endl;
    }
    else if (player1->GetPlayerHealth() <= 0)
    {
        player1->ShowPlayerInfo(iter);
        cout << "\nGAME OVER!\n\nYou've died in the cave due to the monster attacks. :(\nPlease try again." << endl;
    }
    return 0;
}