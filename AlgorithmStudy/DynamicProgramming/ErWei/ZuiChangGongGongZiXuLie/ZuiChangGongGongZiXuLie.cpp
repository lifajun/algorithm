#include <iostream>
#include <string.h>
using namespace std;

int dp[1005][1005];
char s1[1005], s2[1005];

#define max(a, b) (a>b ? a : b)

int main()
{
	while(cin>>s1+1>>s2+1)
	{
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(s1+1), len2 = strlen(s2+1);
		for(int i=1; i<=len1; i++)
		{
			for(int j=1; j<=len2; j++)
			{
				if(s1[i] == s2[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}