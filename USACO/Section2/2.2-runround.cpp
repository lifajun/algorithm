/*
ID: lifajun2
PROG: runround
LANG: C++
*/
#include <cstdio>
#include <cstring>

bool isvalid(int num)
{
	int digit[10] = {0};
	while(num)
	{
		digit[num%10]++;
		num /= 10;
	}
	if(digit[0])	return false;
	for(int i=1; i<=9; i++)
		if(digit[i] > 1)	return false;
	return true;
}

bool isround(int num)
{
	char str[15];
	sprintf(str, "%d", num);
	int len = strlen(str), i=0;
	while(str[i] != 'x')
	{
		int t = i;
		i = (i + str[i] - '0')%len;
		str[t] = 'x';
	}
	if(i != 0)	return false;
	for(int i=0; i<strlen(str); i++)
		if(str[i] != 'x')	return false;
	return true;
}

int main()
{
	int M;
	FILE* in = fopen("runround.in", "r");
	FILE* out = fopen("runround.out", "w");

	fscanf(in, "%d", &M);
	for(int i=M+1;;i++)
	{
		if(isvalid(i) && isround(i))
		{
			fprintf(out, "%d\n", i);
			break;
		}
	}

	return 0;
}