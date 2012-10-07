#include <iostream>
#include <cstring>
using namespace std;

int dp[1000][1000];
char str1[1000], str2[1000];

int min(int a, int b, int c)
{
	if(a < b)
	{
		if(c < a)	return c;
		else	return a;
	}
	else if(c < b)	return c;
	else	return b;
}

int main()
{
	while(cin>>str1>>str2)
	{
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(str1), len2 = strlen(str2);
		for(int i=len1; i>=0; i--)	dp[i][len2] = len1 - i;
		for(int j=len2; j>=0; j--)	dp[len1][j] = len2 - j;
		for(int i = strlen(str1) - 1; i>=0; i--){
			for(int j=strlen(str2) - 1; j>=0; j--)
			{
				if(str1[i] == str2[j])	dp[i][j] = dp[i+1][j+1];
				else	dp[i][j] = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) + 1;
			}
		}
		cout<<dp[0][0]<<endl;
	}
	return 0;
}