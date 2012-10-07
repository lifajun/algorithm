#include <iostream>
#include <algorithm>
using namespace std;

struct Friend
{
	int x;
	int y;
};

int cmp(Friend f1, Friend f2)
{
	return f1.x < f2.x;
}

int main()
{
	int len, wid, n, dp[100], ans;
	Friend arr[100];
	cin>>len>>wid>>n;

	for(int i=0; i<n; i++)
		cin>>arr[i].x>>arr[i].y;
	sort(arr, arr+n, cmp);

	for(int i=0; i<n; i++)	dp[i] = 1;
	ans = 1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if((arr[j].y < arr[i].y) && (dp[i] < dp[j] + 1))
				dp[i] = dp[j] + 1;
			if(dp[i] > ans)
				ans = dp[i];
		}
	}

	cout<<ans<<endl;
	return 0;
}