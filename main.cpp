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
	cout << "What would you like to do?  \n Explore   Check inventory    " ;
	string playerChoice;
	cin >> playerChoice;
	if(playerChoice == "Explore")
	{
		// random number decides if the
		// player encounters an enemy or not
		randnum();

		// test if function call works
		cout << randomNum << "\n";
		if(randomNum == 1)
		{
			// player encounters enemy/enemies
			bool enemy-encounter = true;

			// number of enemies decided by random number
			
		}
		else
		{
			// player doesnt encounter an enemy/enemies
			bool enemy-encounter = false;
		}
	}
}
