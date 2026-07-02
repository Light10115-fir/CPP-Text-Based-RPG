#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*int damaging()
{
	int damagers[100]; // vector for damagers
	for(int i = 0; i<= 99; i++)
	{
		if(damagers[i] >= 1)
		{
			Player.hp = Player.hp - damagers[i];
		}
	}
}*/

int randnum(int randomNum)
{
	// Diff number each time program runs cuz its based on the current time (time changes)
	srand(time(0));

	// Generate a random number between 0 and 3
	randomNum = rand() % 3;

	return 0;
}
