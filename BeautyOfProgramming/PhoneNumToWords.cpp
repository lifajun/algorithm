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

void dfs(int s)
{
	if(s == strlen(str))
	{
		for(int i=0; i<s; i++)
			cout<<c[str[i]-'0'][res[i]];
		cout<<endl;
		return;
	}
	for(unsigned i=0; i<strlen(c[str[s]-'0']); i++)
	{
		res[s] = i;
		dfs(s+1);
	}
}

int main()
{
	while(cin>>str)
	{
		dfs(0);
		cout<<endl;
	}
	return 0;
}