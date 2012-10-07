#include <iostream>
using namespace std;

int nPerson[100], nMinFloor, nTargetFloor;
int N1, N2, N3, belowFloor, aboveFloor;

int main()
{
	int N, i;
	cin>>N;
	belowFloor = 0, aboveFloor = 0;
	for(i=1; i<=N; i++)	cin>>nPerson[i];
	for(N1 = 0, N2 = nPerson[1], N3=0, i = 2; i<=N; i++)
	{
		N3 += nPerson[i];
		aboveFloor += nPerson[i] * (i - 1);
	}
	nMinFloor = aboveFloor, nTargetFloor = 1;
	for(i = 2; i<=N; i++)
	{
		belowFloor += (N1 + N2);
		aboveFloor -= N3;
		if(belowFloor + aboveFloor < nMinFloor)
		{
			nMinFloor = belowFloor + aboveFloor;
			nTargetFloor = i;
		}
		N1 += N2;
		N2 = nPerson[i];
		N3 -= nPerson[i];
	}
	cout<<nTargetFloor<<" "<<nMinFloor<<endl;
}