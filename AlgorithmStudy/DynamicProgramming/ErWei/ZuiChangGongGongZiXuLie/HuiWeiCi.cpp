#include <iostream>
#include <string.h>
using namespace std;

#define max(a, b) (a>b ? a : b)

int N;
char s1[5005], s2[5005];
short dp[5001][5001];

int main()
{
	cin>>N;
	cin>>s1+1;
	for(int i=1; i<=N; i++)
		s2[i] = s1[N+1-i];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++)
		{
			if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout<<N-dp[N][N]<<endl;
	return 0;
}