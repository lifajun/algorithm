/*
ID: lifajun2
PROG: stall4
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

bool map[205][205], vis[205];
int lk[205], N, M;

bool find(int i)
{
	for(int j=1; j<=M; j++)
	{
		if(!vis[j] && map[i][j])
		{
			vis[j] = true;
			if(!lk[j] || find(lk[j]))
			{
				lk[j] = i;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int si, v, ans = 0;
	ifstream in("stall4.in");
	ofstream out("stall4.out");
	in>>N>>M;

	for(int i=1; i<= N; i++)
	{
		in>>si;
		for(int j=1; j<=si; j++)
		{
			in>>v;
			map[i][v] = true;
		}
	}

	for(int i=1; i<=N; i++)
	{
		memset(vis, false, sizeof(vis));
		if(find(i))
			ans++;
	}

	out<<ans<<endl;
	return 0;
}