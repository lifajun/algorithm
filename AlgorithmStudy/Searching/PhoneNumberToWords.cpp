#include <iostream>
#include <cstring>
using namespace std;

char str[100];
char c[10][10] = {
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ"
};

int res[100];

void output()
{
	for(unsigned i=0; i<strlen(str); i++)
		cout<<c[str[i]-'0'][res[i]];
	cout<<endl;
}

int main()
{
	while(cin>>str)
	{
		memset(res, -1, sizeof(res));
		int k=0;
		while(k >= 0)
		{
			res[k]++;
			if(res[k] < strlen(c[str[k]-'0']))
			{
				if(k == strlen(str)-1)	output();
				else	{k++, res[k] = -1;}
			}
			else	k--;
		}
		cout<<endl;
	}
	return 0;
}