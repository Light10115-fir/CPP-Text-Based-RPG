#include "func.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Being // create class for beings
{
	
	private:
		int hp = 0; // int for hitpoints of creature (if needed)

	public:
		string name; // string for name of creature (zombie, player etc)
		int damage; // int for damage of creature (if needed)

		void modHp(int mod){
			hp += mod;
		}

		int getHp(){
			return this -> hp;
		}

};

class Player : public Being
{
	public:
		void deathCheck(){
			if(getHp() <= 0) {
				cout << "You died."; // elden ring type shit
				exit(1);
			}
		}

		void modHp(int mod){
			Being::modHp(mod);
			deathCheck();
		}

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
		deque<string> inventory = {bandage.name, fists.name};

		// Create int to sort through inventory
		int sortInv = sizeof(inventory) / sizeof(inventory[0]);
		
		// Create player
		Player player;
		// Give player name
		player.name = "Player";
		// Give player HP
		player.modHp(10);

		// Check if item is in inv
		
		int bandageCount = 0;

		for(string bandageName : inventory)
		{
			if(bandageName == "Bandage"){
				bandageCount  = bandageCount + 1;
			}
		}
		cout << "bandage count: " << bandageCount << "\n";
	
		// Start game
		while(player.getHp() >0)
		{
			cout << "What would you like to do?  \n Explore (1)	Check character (2)	Quit (3) \n" ;
			// Make playerChoice variable
			string playerChoice = "2";
			// See what player wants to do
			cin >> playerChoice;
			// debugging
			//cout << "playerChoice: " << playerChoice << "\n";
			// See if logic compiler chose
			int ifLogic;
			if(playerChoice == "Explore" || playerChoice == "1")
			{
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

					// Create zombie
					Being zombie;
					// Give zombie name
					zombie.name = "Zombie";
					// Give zombie HP
					zombie.modHp(7);
					// Give zombie damage
					zombie.damage = 4;



					while(zombie.getHp() > 0)
					{
						cout <<	"What do you wanna do?	attack (1)	heal (2)	block (3) \n";
			
						// take playerAct response
						cin >> playerAct;

						if (playerAct == "attack" || playerAct == "1")
						{
							// zombie takes damage
							zombie.modHp(-fists.damage);
							
							if(zombie.getHp() > 0)
							{
								// tell player the results of their attack
								cout << "You attacked! Zombie took " << fists.damage << " damage and has " << zombie.getHp() << " health. \n";
								
								// player takes damage from zombie attack
								player.modHp(-zombie.damage);

								// tell player the results of the zombie's attack
								cout << "Zombie attacked you! You took " << zombie.damage << " damage and have " << player.getHp() << " health. \n";
							}
							else
							{
								cout << "Zombie died! \n";
							}
						}
						else if(playerAct == "heal" || playerAct == "2")
						{
							auto foundBandage = find(inventory.begin(), inventory.end(), bandage.name);
							if(foundBandage!=inventory.end())
							{
								inventory.erase(foundBandage);
								player.modHp(bandage.healValue);
								cout << "You used " << bandage.name << " to heal! You have " << player.getHp() << " health now. \n";
							}
							else cout << "You do not have a bandage! \n";
						}
					}
				}
				else
				{
					// player doesnt encounter an enemy/enemies
					enemyEncounter = false;
				}
			}
			else if (playerChoice == "Check character" || playerChoice == "2")
			{
				// Print inventory
				cout << "Inventory: \n";
				for(string i : inventory)
				{
					// print each item in inventory
					cout << i << ' ';
				}
				cout << "\n";
				// Print player hp
				cout << " Player HP: " << player.getHp() << "\n";
			}
			// Quit game
			else if(playerChoice == "Quit game" || playerChoice == "3")
			{
				cout << "Quitting... \n";
				return 0;
			}
		//}
	}
}
