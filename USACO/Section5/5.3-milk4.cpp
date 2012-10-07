/*
ID: lifajun2
PROG: milk4
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

int Q, P, q[105], used[105];
bool dp[20005], finished;
ifstream fin("milk4.in");
ofstream fout("milk4.out");

bool isOk(int k)
{
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for(int i=1; i<=k; i++)
		for(int j=q[used[i]]; j<=Q; j++)
			dp[j] = dp[j] || dp[j-q[used[i]]];
	return dp[Q];
}

void dfs(int k, int s)
{
	if(s > k)
	{
		if(isOk(k))
		{
			fout<<k;
			for(int i=1; i<=k; i++)
				fout<<" "<<q[used[i]];
			fout<<endl;
			finished = true;
		}
		return;
	}		
	for(int i=used[s-1]+1; i<=P-k+s; i++)
	{
		used[s] = i;
		dfs(k, s+1);
		if(finished)	return;
	}
}

int main()
{
	fin>>Q>>P;
	for(int i=1; i<=P; i++)	fin>>q[i];
	sort(q+1, q+P+1);

	finished = false;
	for(int i=1; i<= P; i++)
	{
			dfs(i, 1);
			if(finished)	break;
	}

	return 0;
}