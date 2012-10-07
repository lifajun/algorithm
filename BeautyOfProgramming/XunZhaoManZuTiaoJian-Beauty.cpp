#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

__int64 m[1000];

int main()
{
	int N, i, j;
	cin>>N;
	memset(m, 0, sizeof(m));
	m[1] = 1;

	int NoUpdate = 0;
	for(i=1, j=10%N; ;i++, j=(j*10)%N)
	{
		bool flag = false;
		if(m[j] == 0)
		{
			flag = true;
			m[j] = pow(10.0, (double)i);
		}

		for(int k=1; k<N; k++)
		{
			if(m[k] > 0 && m[(k+j)%N] == 0 && pow(10.0, (double)i) > m[k])
			{
				flag = true;
				m[(k+j)%N] = pow(10.0, (double)i) + m[k];
			}
		}
		if(!flag)	NoUpdate++;
		else	NoUpdate = 0;

		if(NoUpdate == N || m[0])
			break;
	}

	if(m[0])		cout<<m[0]<<endl;
	else	cout<<"Not Exist"<<endl;

	return 0;
}