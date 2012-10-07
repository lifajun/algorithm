#include <iostream>
#include <string.h>
using namespace std;

#define max(a, b)(a>b ? a : b)

unsigned int dp[35][35];
int a[35], path[35][35];

int getMax(int l, int r)
{
	if(dp[l][r])	return dp[l][r];
	if(l>r)
		dp[l][r] = 1, path[l][r] = 0;
	else if(l == r)
		dp[l][r] = a[l], path[l][r] = l;
	else
	{
		for(int i=l; i<=r; i++)//以l到r每个节点为根来尝试
		{
			unsigned int x = getMax(l, i-1) * getMax(i+1, r) + a[i];
			if(x > dp[l][r])
			{
				dp[l][r] = x;
				path[l][r] = i;
			}
		}
	}
	return dp[l][r];
}

void printPath(int l, int r)
{
	if(path[l][r])
	{
		cout<<path[l][r]<<" ";
		printPath(l, path[l][r]-1);
		printPath(path[l][r]+1, r);
	}
}

int main()
{
	int N;
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>a[i];
	memset(dp, 0, sizeof(dp));
	cout<<getMax(1, N)<<endl;
	printPath(1, N);
	cout<<endl;
	return 0;
}