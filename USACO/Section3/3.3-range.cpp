/*
ID: lifajun2
PROG: range
LANG: C++
*/
#include <fstream>
using namespace std;

int field[255][255], N, num[255];

int min(int a, int b, int c)
{
	int temp = a < b ? a : b;
	return temp < c ? temp : c;
}

int main()
{
	char c;
	ifstream in("range.in");
	ofstream out("range.out");

	in>>N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			in>>c, field[i][j] = c-'0';

	for(int i=N; i>=1; i--)
	for(int j=N; j>=1; j--)
	if(field[i][j])
	{
		field[i][j] = min(field[i+1][j], field[i][j+1], field[i+1][j+1]) + 1;
		for(int k=2; k<=field[i][j]; k++)
			num[k]++;
	}

	for(int i=2; i<=N; i++)
		if(num[i])
			out<<i<<" "<<num[i]<<endl;

	return 0;
}