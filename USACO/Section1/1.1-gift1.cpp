/*
ID: lifajun2
PROG: gift1
LANG: C++
*/
//#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int n;
struct Person
{
	char name[15];
	int init;
	int final;
}per[11];

int getIndex(char* name)
{
	for(int i=0; i<n; i++)
		if(strcmp(name, per[i].name) == 0)
			return i;
	return -1;
}

int main()
{
	int money, k;
	char na[15];
	ifstream infile("gift1.in");
	ofstream outfile("gift1.out");
	//scanf("%d", &n);
	infile>>n;
	for(int i=0; i<n; i++)
	{
		/*scanf("%s", &per[i].name);*/
		infile>>per[i].name;
		per[i].init = 0, per[i].final = 0;
	}
	for(int i=0; i<n; i++)
	{
		/*scanf("%s%d%d", na, &money, &k);*/
		infile>>na>>money>>k;
		int idx = getIndex(na);
		per[idx].init = money, per[idx].final += money;
		for(int i=0; i<k; i++)
		{
			/*scanf("%s", na);*/
			infile>>na;
			int idx2 = getIndex(na);
			per[idx2].final += money/k;
			per[idx].final -= money/k;
		}
	}
	for(int i=0; i<n; i++)
		outfile<<per[i].name<<" "<<per[i].final - per[i].init<<endl;
	return 0;
}