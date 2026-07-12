#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <deque>

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

// Function  to generate random number
int randnum(int number)
{
	int randomNum;

	// Diff number each time program runs cuz its based on the current time (time changes)
	srand(time(0));

	// Generate a random number between 0 and 3
	randomNum = rand() % number + 1;

	return randomNum;
}

// Please work i beg you
// doesnt work kms
/*int findItem(int array[], int item, int itemClass)
{
	if(itemClass > 0)
	{
		deque<int>::iterator it = find(array.begin(), array.end(), itemClass:item);
		if(it!=numbers.end())
		{
			it = numbers.erase(it);
		}
	}

	else if(itemClass < 0)
	{
		deque<int>::iterator it = find(array.begin(), array.end(), item);
		if(it!=numbers.end)
		{
			it = numbers.erase(it);
		}
	}
}*/
		//find(array.begin(), array.end(), itemClass::item)
