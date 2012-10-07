/*
ID: lifajun2
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstring>

#define min(a, b) (a < b ? a : b)
#define MAX 10000000
#define set(a, i) (a = a | (1<<i))
#define clr(a, i) (a = a & (~(1<<i)))
#define test(a, i) (a & (1<<i))

unsigned prime[(MAX>>5)+10];

void getPrime()
{
	memset(prime, 0xffffffff, sizeof(prime));
	for(int i=2; i<sqrt((double)MAX); i++)
	{
		if(test(prime[i>>5], i%(1<<5)))
		{
			for(int j=i*i; j<MAX; j+=i)
				clr(prime[j>>5], j%(1<<5)); 
		}
	}
}

bool ispalin(int num)
{
	int a[10], idx = 0;
	while(num)
		a[idx++] = num%10,  num/=10;
	int l = 0, r = idx-1;
	while(l < r)
		if(a[l++] != a[r--])	return false;
	return true;
}

int main()
{
	int a, b;
	FILE* in = fopen("pprime.in", "r");
	FILE *out = fopen("pprime.out", "w");
	
	getPrime();
	fscanf(in, "%d%d", &a, &b);
	b = min(b, MAX);

	for(int i=a; i<=b; i++)
		if(test(prime[i>>5], i%(1<<5)) && ispalin(i))
			fprintf(out, "%d\n", i);
	return 0;
}