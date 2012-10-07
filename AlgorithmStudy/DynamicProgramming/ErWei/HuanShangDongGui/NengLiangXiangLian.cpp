#include <iostream>
#include <string.h>

using namespace std;

#define max(a, b) (a > b ? a : b)

int dp[205][205];
int a[205];

int main()
{
	int N, max = 0;
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>a[i];
	for(int i=N+1; i<=2*N; i++)
		a[i] = a[i-N];
	memset(dp, 0, sizeof(dp));

	for(int i=2*N-1; i>=1; i--)
		for(int j=i; j<=2*N-1; j++)
			for(int k=i; k<j; k++)
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i]*a[k+1]*a[j+1]);

	for(int i=1; i<=N; i++)
		if(dp[i][i+N-1] > max)
			max = dp[i][i+N-1];
	cout<<max<<endl;
	return 0;
}