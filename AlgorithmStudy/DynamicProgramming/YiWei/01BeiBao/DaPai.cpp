#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int dp[1000], path[1000], totalW, N, w[100];
	bool ans[100];
	memset(dp, 0, sizeof(dp));
	memset(path, 0, sizeof(path));
	cin>>totalW>>N;

	dp[0] = 1;
	for(int i=1; i<=N; i++)
	{
		cin>>w[i];
		for(int j=totalW; j>=w[i]; j--)
		{
			if(dp[j-w[i]])
			{
				dp[j] += dp[j-w[i]];
				if(!path[j])
					path[j] = i;
			}
		}
	}
	if(!dp[totalW])
		cout<<0<<endl;
	else if(dp[totalW] > 1)
		cout<<-1<<endl;
	else
	{
		memset(ans, false, sizeof(ans));
		int i=totalW;
		while(i>0)
		{
			ans[path[i]] = true;
			i -= w[path[i]];
		}
		for(int i=1; i<=N; i++)
			if(!ans[i])
				cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}