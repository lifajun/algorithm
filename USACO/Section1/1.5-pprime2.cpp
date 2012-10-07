/*
ID: lifajun2
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

FILE* in = fopen("pprime.in", "r");
FILE* out = fopen("pprime.out", "w");
int a, b;

bool isprime(int num)
{
	for(int i=2; i<=sqrt((double)num); i++)
		if(num % i == 0)	return false;
	return true;
}

void getOdd(int st, int ed)
{
	char str[10];
	for(int i=st; i<=ed; i++)
	{
		sprintf(str, "%d", i);
		int p=strlen(str)-2, q = strlen(str);
		while(p >= 0)
			str[q++] = str[p--];
		str[q] = '\0';
		int num = atoi(str);
		if(isprime(num) && num>=a && num<=b)
			fprintf(out, "%d\n", num);
	}
}

int main()
{
	fscanf(in, "%d%d", &a, &b);
	for(int i=a; i<=11; i++)
		if(isprime(i))	fprintf(out, "%d\n", i);
	getOdd(10, 99);
	getOdd(100, 999);
	getOdd(1000, 9999);
	return 0;
}