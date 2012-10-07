#include <iostream>
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

void dfs(int s)
{
	if(s > 7)
	{
		for(int i=1; i<=7; i++)
			cout<<c[i]<<" ";
		cout<<endl;
		total++;
	}
	else
	{
		for(int i=1; i<=4; i++)
		{
			c[s] = i;
			if(ok(s))
				dfs(s+1);
		}
	}
}
int main()
{
	total = 0;
	dfs(1);
	cout<<total<<endl;
	return 0;
}