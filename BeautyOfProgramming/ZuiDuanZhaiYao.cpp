#include <iostream>
#include <cstring>
using namespace std;

char des[100][20], key[100][20];
int pstart, pend, minstart, minend, minlength;
int des_L, key_L;

bool isExistAll()
{
	int i, j;
	for(i=0; i<key_L; i++)
	{
		for(j=pstart; j<=pend && strcmp(key[i], des[j]) != 0; j++);
		if(j > pend)	return false;
	}
	return true;
}

int main()
{
	cin>>des_L;
	for(int i=0; i<des_L; i++)	cin>>des[i];
	cin>>key_L;
	for(int i=0; i<key_L; i++)	cin>>key[i];

	pstart = 0, pend = 0, minlength = des_L;
	while(pend < des_L)
	{
		while(!isExistAll() && pend < des_L)	pend++;

		while(isExistAll())
		{
			if((pend - pstart + 1) < minlength)
			{
				minlength = pend-pstart+1;
				minstart = pstart, minend = pend;
			}
			pstart++;
		}
	}
	cout<<minlength<<endl;
	for(int i=minstart; i<=minend; i++)	cout<<des[i]<<" ";
	cout<<endl;
	return 0;
}