/*
ID: lifajun2
PROG: ratios
LANG: C++
*/
#include <fstream>
using namespace std;

int Ba[4], O[4], W[4];

int main()
{
	ifstream in("ratios.in");
	ofstream out("ratios.out");
	
	for(int i=0; i<=3; i++)
		in>>Ba[i]>>O[i]>>W[i];

	if(Ba[0] + O[0] + W[0] == 0)
	{
		out<<0<<" "<<0<<" "<<0<<endl;
		return 0;
	}

	int t1 = 101, t2 = 101, t3 = 101, ti;
	for(int i=0; i<=100; i++)
	for(int j=0; j<=100; j++)
	for(int k=0; k<=100; k++)
	{
		if(i == 0 && j == 0 && k == 0)	continue;
		int sum1 = i*Ba[1] + j*Ba[2] + k*Ba[3];
		int sum2 = i*O[1] + j*O[2] + k*O[3];
		int sum3 = i*W[1] + j*W[2] + k*W[3];
		for(int t=1; t*Ba[0] <= sum1; t++)
		if(t*Ba[0] == sum1 && t*O[0] == sum2 && t*W[0] == sum3 && i+j+k < t1+t2+t3)
		{
			t1 = i, t2 = j, t3 = k, ti = t;
			break;
		}
	}

	if(t1 == 101)
		out<<"NONE"<<endl;
	else
		out<<t1<<" "<<t2<<" "<<t3<<" "<<ti<<endl;

	return 0;
}