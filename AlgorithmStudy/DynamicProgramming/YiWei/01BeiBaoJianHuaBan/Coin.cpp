#include <iostream>
#include <string.h>
using namespace std;

int A[101], C[101], b[100005];
bool dp[100005];
int n, m;

int main()
{
	while(cin>>n>>m, n+m)
	{
		for(int i=1; i<=n; i++)
			cin>>A[i];
		for(int i=1; i<=n; i++)
			cin>>C[i];

		memset(dp, false, sizeof(dp));
		dp[0] = true;
		int ans = 0;
		for(int i=1; i<=n; i++)
		{
			memset(b, 0, sizeof(b));
			for(int j=A[i]; j<=m; j++)
				if(dp[j-A[i]] && !dp[j] && b[j-A[i]]+1 <= C[i])
				{
					dp[j] = true;
					b[j] = b[j-A[i]]+1;
					ans++;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}