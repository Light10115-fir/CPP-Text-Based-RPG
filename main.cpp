#include "func.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Being // create class for being
{
	std::string name; // string for name of creature (zombie, player etc)
	int hp; // int for hitpoints of creature (if needed)
	int damage; // int for damage of creature (if needed)
};

int main()
{
	cout << "What would you like to do?  \n Explore (1)   Check inventory    " ;
	string playerChoice;
	cin >> playerChoice;
	if(playerChoice == "Explore" || "1")
	{
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
		cout << "randomNum: " << randomNum << "\n" << "enemyEncounter" << enemyEncounter << "\n";
	}
}
