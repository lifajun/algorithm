#include <iostream>
using namespace std;

int main()
{
	int dp1[100], dp2[100], T[100], N, max;
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>T[i];

	for(int i=0; i<N; i++)	dp1[i] = dp2[i] = 1;

	for(int i=1; i<N; i++)
	{
		for(int j=0; j<i; j++)
		{
			if((T[j] < T[i]) && (dp1[i] < dp1[j] + 1))
				dp1[i] = dp1[j] + 1;
		}
	}

	for(int i=N-2; i>=0; i--)
	{
		for(int j=N-1; j>i; j--)
		{
			if((T[i] > T[j]) && (dp2[i] < dp2[j] + 1))
				dp2[i] = dp2[j] + 1;
		}
	}

	max = 0;
	for(int i=0; i<N; i++)
		if(dp1[i] + dp2[i] > max)
			max = dp1[i] + dp2[i];

	cout<<N-max+1<<endl;
	return 0;
}