#include <iostream>
#include <memory.h>
using namespace std;

bool dp[100][1000];

int main()
{
	int n, hi, ans = 0;
	cin>>n;
	memset(dp, false, sizeof(dp));
	for(int i=0; i<n; i++)
		dp[i][0] = true;
	for(int i=0; i<n; i++)
	{
		while(1)
		{
			cin>>hi;
			if(hi == -1)	break;
			for(int j=999; j>=hi; j--)
				if(dp[i][j-hi])
					dp[i][j] = true;
		}
	}
	for(int i=0; i<999; i++)
	{
		bool can_do = true;
		for(int j=0; j<n; j++)
		{
			if(!dp[j][i])
			{
				can_do = false;
				break;
			}
		}
		if(can_do)
			ans = i;
	}
	cout<<ans<<endl;
	return 0;
}