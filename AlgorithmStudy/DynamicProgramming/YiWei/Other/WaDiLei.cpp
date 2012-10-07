#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int dp[21], g[21][21], N, W[21], path[21];
	memset(dp, 0, sizeof(dp));
	memset(path, 0, sizeof(path));
	memset(g, 0, sizeof(g));
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>W[i];
	for(int i=1; i<N; i++)
	{
		for(int j=i+1; j<=N; j++)
			cin>>g[i][j];
	}

	for(int i=N; i>=1; i--)
	{
		for(int j=i+1; j<=N; j++)
		{
			if(g[i][j] && (dp[j] > dp[i]))
			{
				dp[i] = dp[j];
				path[i] = j;
			}
		}
		dp[i] += W[i];
	}

	int max = 0, max_index, index;
	for(int i=1; i<=N; i++)
	{
		if(dp[i] > max)
			max = dp[i], max_index = i;
	}
	cout<<max_index;
	index = path[max_index];
	while(index)
	{
		cout<<"->"<<index;
		index = path[index];
	}
	cout<<endl;
	cout<<max<<endl;
	return 0;
}