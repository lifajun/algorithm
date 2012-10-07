#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[260];
	int n;
	cin>>str>>n;
	for(int i=1; i<=n; i++)
	{
		int pos = 0;
		while(pos<strlen(str)-1 && str[pos] <= str[pos+1])	pos++;
		for(int i=pos; i<strlen(str); i++)	str[i] = str[i+1];
	}
	int i;
	for(i=0; i<strlen(str); i++)
		if(str[i] != '0')	break;
	if(i == strlen(str))
	{
		cout<<0<<endl;
		return 0;
	}
	for(int j=i; j<strlen(str); j++)	cout<<str[j];
	cout<<endl;
	return 0;
}