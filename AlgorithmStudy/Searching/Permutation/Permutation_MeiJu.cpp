#include <iostream>
#include <windows.h>
using namespace std;

int a[15], total;

bool check(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] == a[s])
			return false;
	return true;
}

int main()
{
	int time = GetTickCount();
	for(a[1] = 1; a[1] <= 9; a[1]++)
	{
		for(a[2] = 1; a[2] <= 9; a[2]++)
		{
			if(!check(2))	continue;
			for(a[3] = 1; a[3] <= 9; a[3]++)
			{
				if(!check(3)) continue;
				for(a[4] = 1; a[4]<=9; a[4]++)
				{
					if(!check(4))	continue;
					for(a[5] = 1; a[5] <=9; a[5]++)
					{
						if(!check(5))	continue;
						for(a[6] = 1; a[6] <= 9; a[6]++)
						{
							if(!check(6)) continue;
							for(a[7] = 1; a[7]<=9; a[7]++)
							{
								if(!check(7))	continue;
								for(a[8] = 1; a[8]<=9; a[8]++)
								{
									if(!check(8))	continue;
									for(a[9] = 1; a[9]<=9; a[9]++)
									{
										if(!check(9))	continue;
										else
											total++;
									}
								}
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