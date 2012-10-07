#include <iostream>
#include <string.h>
using namespace std;

int MM[101][101], T[101][101];
int rmb[101], rp[101], ti[101];

int main()
{
	int N, M, R;
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>rmb[i]>>rp[i]>>ti[i];
	cin>>M>>R;

	memset(MM, 0, sizeof(MM));
	memset(T, 0, sizeof(T));
	MM[0][0] = 1;

	for(int i=1; i<=N; i++)
	{
		for(int j=M; j>=rmb[i]; j--)
			for(int k=R; k>=rp[i]; k--)
			{
				if(MM[j-rmb[i]][k-rp[i]] > 0)
				{
					if(MM[j-rmb[i]][k-rp[i]] + 1 > MM[j][k])
					{
						MM[j][k] = MM[j-rmb[i]][k-rp[i]] + 1;
						T[j][k] = T[j-rmb[i]][k-rp[i]] + ti[i];
					}
					else if(MM[j-rmb[i]][k-rp[i]] + 1 ==  MM[j][k])
					{
						if(T[j][k] > T[j-rmb[i]][k-rp[i]] + ti[i])
							T[j][k] = T[j-rmb[i]][k-rp[i]] + ti[i];
					}
				}
			}
	}

	int mm = MM[1][1], ans = T[1][1];
	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=R; j++)
		{
			if(MM[i][j] > mm)
			{
				mm = MM[i][j];
				ans = T[i][j];
			}
			else if(MM[i][j] == mm)
			{
				if(T[i][j] < ans)
					ans = T[i][j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}