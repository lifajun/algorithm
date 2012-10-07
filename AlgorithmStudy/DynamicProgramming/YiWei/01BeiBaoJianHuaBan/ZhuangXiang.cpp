#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int V, N, v, i;
	bool dp[1000];
	
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	cin>>V>>N;
	for(i=0; i<N; i++)
	{
		cin>>v;
		for(int j=V; j>=v; j--)
		{
			if(dp[j-v])
				dp[j] = true;
		}
	}
	for(i=V; i>=0; i--)
		if(dp[i])
			break;
	cout<<V-i<<endl;
	
	return 0;
}