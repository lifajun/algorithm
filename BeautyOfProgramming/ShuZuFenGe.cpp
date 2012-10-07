#include <iostream>
#include <cstring>
using namespace std;

#define min(a, b) (a < b ? a : b)

int arr[100], n;
bool dp[100][1000];

int main()
{
	cin>>n;
	int sum = 0;
	for(int i=1; i<=n; i++)
		cin>>arr[i], sum += arr[i];
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;

	for(int k=1; k<=n; k++)
	{
		for(int i=min(k, n); i>=1; i--)
			for(int v = 1; v<=sum/2; v++)
				if(v >= arr[k] && dp[i-1][v-arr[k]])
					dp[i][v] = true;
	}
	int v;
	for(v=sum/2; v>=1 && !dp[n/2][v]; v--);
	cout<<v<<endl;
	return 0;
}