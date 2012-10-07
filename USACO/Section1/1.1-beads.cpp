/*
ID: lifajun2
PROG: beads
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

#define max(a, b)(a > b ? a : b)
char neck[1100], str[400];
int n;

int getLeft(int i)
{
	int tmp1 = 1;
	for(int j = i-2; j >= (i-n); j--)
	{
		if(neck[j] == neck[i-1] || neck[j] == 'w')
			tmp1++;
		else	break;
	}
	return tmp1;
}

int getRight(int i)
{
	int tmp2 = 1;
	for(int j = i+1; j <= i+n-1; j++)
	{
		if(neck[j] == neck[i] || neck[j] == 'w')
			tmp2++;
		else break;
	}
	return tmp2;
}

int main()
{
	ifstream infile("beads.in");
	ofstream outfile("beads.out");
	infile>>n>>str;
	strcpy(neck, str);
	strcat(neck, str);
	strcat(neck, str);

	int max = 0;
	for(int i=n; i<2*n; i++)
	{
		int tmp1 = 1, tmp2 = 1;
		if(neck[i-1] == 'w')
		{
			neck[i-1] = 'r', tmp1 = max(getLeft(i), tmp1), neck[i-1] = 'w';
			neck[i-1] = 'b', tmp1 = max(getLeft(i), tmp1), neck[i-1] = 'w';
		}
		else	tmp1 = max(getLeft(i), tmp1);

		if(neck[i] == 'w')
		{
			neck[i] = 'r', tmp2 = max(getRight(i), tmp2), neck[i] = 'w';
			neck[i] = 'b', tmp2 = max(getRight(i), tmp2), neck[i] = 'w';
		}
		else	tmp2 = max(getRight(i), tmp2);
		if(tmp1 + tmp2 > max)
			max = tmp1 + tmp2;
	}
	outfile<<((max > n) ? n : max)<<endl;
	return 0;
}