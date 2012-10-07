#include <iostream>
#include <cstring>
using namespace std;

char s[10000];
long long dp[10000];

int main()
{
	while(cin>>s+1)
	{
		if(strcmp(s+1, "0") == 0)
			break;
		memset(dp, 0, sizeof(dp));
		dp[0] = dp[1] = 1;
		int len = strlen(s+1);
		for(int i=2; i<=len; i++)
		{
			if(s[i] == '0')
				dp[i] = dp[i-2];
			else
			{
				dp[i] = dp[i-1];
				int temp = (s[i-1]-'0')*10 + s[i]-'0';
				if(temp > 10 && temp < 27)
					dp[i] += dp[i-2];
			}
		}
		cout<<dp[len]<<endl;
	}
	return 0;
}