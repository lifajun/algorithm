/*
ID: lifajun2
PROG: friday
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

int cnt[7], N;
int month[2][13] = {{31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30},
{31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30}};

int  is_leap(int y)
{
	if((y%4 == 0 && y%100 != 0) || (y%400 == 0))	return 1;
	return 0;
}

int main()
{
	ifstream infile("friday.in");
	ofstream outfile("friday.out");
	infile>>N;
	memset(cnt, 0, sizeof(cnt));
	int days = -19;
	for(int y = 1900; y<= 1900+N-1; y++)
	{
		for(int m=1; m<=12; m++)
		{
			days += month[is_leap(y)][m-1];
			cnt[days%7]++;
		}
	}
	outfile<<cnt[5]<<" "<<cnt[6];
	for(int i=0; i<=4; i++)
		outfile<<" "<<cnt[i];
	outfile<<endl;
	return 0;
}