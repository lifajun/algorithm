#include <iostream>
#include <string.h>

using namespace std;

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int mindp[205][205], maxdp[205][205];
int a[205], sum[205];

int main()
{
	int N;
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>a[i];
	for(int i=N+1; i<=2*N; i++)
		a[i] = a[i-N];
	for(int i=1; i<=2*N; i++)
		for(int j=1; j<=2*N; j++)
			mindp[i][j] = 100000000;
	memset(maxdp, 0, sizeof(maxdp));
	memset(sum, 0, sizeof(sum));

	sum[1] = a[1];
	for(int i=2; i<=2*N; i++)
		sum[i] = sum[i-1] + a[i];

	for(int i = 2*N-1; i >= 1; i--)
	{
		for(int j = i; j <= 2*N-1; j++)
		{
			if(i == j)
				mindp[i][j] = 0;
			else
			{
				for(int k=i; k<j; k++)
				{
					mindp[i][j] = min(mindp[i][j], mindp[i][k] + mindp[k+1][j]); 
					maxdp[i][j] = max(maxdp[i][j], maxdp[i][k] + maxdp[k+1][j]);
				}
				mindp[i][j] += sum[j] - sum[i-1];
				maxdp[i][j] += sum[j] - sum[i-1];
			}
		}
	}
	int minans = mindp[1][N], maxans = maxdp[1][N];
	for(int i=2; i<=N; i++)
	{
		if(mindp[i][i+N-1] < minans)
			minans = mindp[i][i+N-1];
		if(maxdp[i][i+N-1] > maxans)
			maxans = maxdp[i][i+N-1];
	}
	cout<<minans<<endl<<maxans<<endl;
	return 0;
}