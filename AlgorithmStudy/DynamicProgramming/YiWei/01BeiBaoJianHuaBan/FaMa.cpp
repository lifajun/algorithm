#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	bool dp[1001];
	int a[6], w[6] = {1, 2, 3, 5, 10, 20};
	int ans = 0;
	memset(dp, false, sizeof(dp));
	for(int i=0; i<6; i++)
		cin>>a[i];
	dp[0] = true;
	for(int i=0; i<6; i++)
	{
		for(int j=1; j<=a[i]; j++)
		{
			for(int k=1000; k>=w[i]; k--)
				if(dp[k-w[i]])
					dp[k] = true;
		}
	}
	for(int i=1; i <= 1000; i++)
		if(dp[i])
			ans ++;

	cout<<ans<<endl;
	return 0;
}