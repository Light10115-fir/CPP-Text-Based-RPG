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

// Create child Weapons class, Items parent
class Weapon : public Items
{
	public:
		int damage;
		string name;
};

// Create child MiscItems class, Items parent
class MiscItems : public Items
{
	public:
		int healValue;
		string name;
};

int main()
{
	// start game
	//while(true){
		// Create sword weapon
		Weapon sword;
		// Give sword damage value
		sword.damage = 5;
		// Give sword name
		sword.name = "Sword";
		// Create fists weapon
		Weapon fists;
		// Give fists name
		fists.name = "Fists";
		// Give fists damage
		fists.damage = 3;
		// Create bandage item
		MiscItems bandage;
		// Give bandage name
		bandage.name = "Bandage";
		// Give bandage heal value
		bandage.healValue = 7;
		// Create inventory
		string inventory[5] = {bandage.name, fists.name};
		// Create int to sort through inventory
		int sortInv = sizeof(inventory) / sizeof(inventory[0]);
		// Create zombie
		Being zombie;
		// Give zombie name
		zombie.name = "Zombie";
		// Give zombie HP
		zombie.hp = 7;
		// Give zombie damage
		zombie.damage = 4;
		// Create player
		Being player;
		// Give player name
		player.name = "Player";
		// Give player HP
		player.hp = 10;
		// Start game
		while(player.hp >0)
		{
			cout << "What would you like to do?  \n Explore (1)	Check inventory (2)	Quit (3) \n" ;
			// Make playerChoice variable
			string playerChoice = "2";
			// See what player wants to do
			cin >> playerChoice;
			// debugging
			cout << "playerChoice: " << playerChoice << "\n";
			// See if logic compiler chose
			int ifLogic;
			if(playerChoice == "Explore" || playerChoice == "1")
			{
				// If logic variable is 1
				ifLogic = 1;
				// random number decides if the
				// player encounters an enemy or not
				int randomNum = randnum(2);

				// enemy encounter boolean	
				bool enemyEncounter;
		
				int numberEnemies;
				if(randomNum == 1)
				{
					// player acts
					string playerAct;
					// number of enemies decided by random number
					numberEnemies = randnum(20);

					// tell player they encountered enemy
					// and ask them what they wanna do
					cout << "You encountered a zombie! \n";
					while(zombie.hp > 0)
					{
						cout <<	"What do you wanna do?	attack (1)	heal (2)	block (3) \n";
			
						// take playerAct response
						cin >> playerAct;
						if (playerAct == "attack" || playerAct == "1")
						{
							// zombie takes damage
							zombie.hp = zombie.hp - fists.damage;

							// tell player the results of their attack
							cout << "You attacked! Zombie took " << fists.damage << " damage and has " << zombie.hp << " health. \n";

							// player takes damage from zombie attack
							player.hp = player.hp - zombie.damage;

							// tell player the results of the zombie's attack
							cout << "Zombie attacked you! You took " << zombie.damage << " damage and have " << player.hp << " health. \n";
						}
					}
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
			else if (playerChoice == "Check inventory" || playerChoice == "2")
			{
				// ifLogic variable is 2
				ifLogic = 2;
				for(string i : inventory)
				{
					// print each item in inventory
					cout << i << ' ';
				}
				cout << "\n";
				cout << "If logic: " << ifLogic << "\n";
			}
			else if (playerChoice == "Quit game" || playerChoice == "3")
			{
				ifLogic = 3;
				cout << "If logic: " << ifLogic << "\n Quitting... \n";
				return 0;
			}
		//}
	}
}
