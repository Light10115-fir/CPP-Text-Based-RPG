#include "func.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Being // create class for beings
{
	public:
		string name; // string for name of creature (zombie, player etc)
		int hp; // int for hitpoints of creature (if needed)
		int damage; // int for damage of creature (if needed)
};

// Create parent Items class
class Items
{
	public:	
};

// Create child Weapons class
class Weapon : public Items
{
	public:
		int damage;
		string name;
};

// Create child MiscItems class
class MiscItems : public Items
{
	public:
		int healValue;
		string name;
};

int main()
{
	// Create sword weapon
	Weapon sword;
	// Give sword damage value
	sword.damage = 5;
	// Give sword name
	sword.name = "Sword";
	// Create bandage item
	MiscItems bandage;
	// Give bandage name
	bandage.name = "Bandage";
	// Give sword heal value
	bandage.healValue = 10;
	// Create inventory
	string inventory[5] = {sword.name, bandage.name};
	// Create int to sort through inventory
	int sortInv = sizeof(inventory) / sizeof(inventory[0]);
	// Start game
	cout << "What would you like to do?  \n Explore (1)	Check inventory(2)	" ;
	// Make playerChoice variable
	string playerChoice = "2";
	// See what player wants to do
	cin >> playerChoice;
	// debugging
	cout << "playerChoice: " << playerChoice << "\n";
	// See if logic compiler chose
	int ifLogic;
	if(playerChoice == "Explore" || "1")
	{
		// If logic variable is 1
		ifLogic = 1;
		// random number decides if the
		// player encounters an enemy or not
		int randomNum = randnum(2);
		
		bool enemyEncounter;
		
		int numberEnemies;
		if(randomNum == 1)
		{
			// player encounters enemy/enemies
			enemyEncounter = true;

			// number of enemies decided by random number
			numberEnemies = randnum(20);
		}
		else
		{
			// player doesnt encounter an enemy/enemies
			enemyEncounter = false;
		}
		// debugging
		cout << "randomNum: " << randomNum << "\n" << "enemyEncounter: " << enemyEncounter << "\n";
		cout << "If logic: " << ifLogic << "\n";
	}
	else if (playerChoice == "Check inventory" || "2")
	{
		// ifLogic variable is 2
		ifLogic = 2;
		for(int i = 0; i >= sortInv; i++)
		{
			cout << inventory[i] << ' ';
		}
		cout << "\n";
		cout << "If logic: " << ifLogic << "\n";
	}
}
