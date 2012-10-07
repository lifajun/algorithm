#include <iostream>
#include <windows.h>
using namespace std;

int map[8][8] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 1, 0, 1},
	{0, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 1, 1, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 1, 0, 0, 0},
	{0, 1, 0, 1, 1, 1, 0, 0}
};

int c[8], total;

bool ok(int s)
{
	for(int i=1; i<s; i++)
		if(map[i][s] && c[i] == c[s])
			return false;
	return true;
}

int main()
{
	int time = GetTickCount();
	for(c[1] = 1; c[1]<=4; c[1]++)
	{
		for(c[2] = 1; c[2] <= 4; c[2]++)
		{
			if(!ok(2))	continue;
			for(c[3] = 1; c[3] <= 4; c[3]++)
			{
				if(!ok(3))	continue;
				for(c[4] = 1; c[4] <= 4; c[4] ++)
				{
					if(!ok(4))	continue;
					for(c[5] = 1; c[5] <= 4; c[5]++)
					{
						if(!ok(5))	continue;
						for(c[6] = 1; c[6] <= 4; c[6]++)
						{
							if(!ok(6))	continue;
							for(c[7] = 1; c[7] <= 4; c[7]++)
							{
								if(!ok(7))	continue;
								else	total++;
							}
						}
					}
				}
			}
		}
	}

	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}