int damaging()
{
	int damagers[100]; // vector for damagers
	for(int i = 0; i<= 99; i++)
	{
		if(damagers[i] >= 1)
		{
			Player.hp = Player.hp - damagers[i];
		}
	}
}
