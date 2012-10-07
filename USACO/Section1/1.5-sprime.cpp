/*
ID: lifajun2
PROG: sprime
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstring>

FILE* in = fopen("sprime.in", "r");
FILE* out = fopen("sprime.out", "w");
int N,  result;

bool isprime(int num)
{
	for(int i=2; i<=sqrt((double)num); i++)
		if(num % i == 0)	return false;
	return true;
}

void dfs(int s)
{
	if(s > N)
		fprintf(out, "%d\n", result);
	else
	{
		unsigned temp = result;
		result = temp*10 + 1;
		if(isprime(result))
			dfs(s+1);
		result = temp*10 + 3;
		if(isprime(result))
			dfs(s+1);
		result = temp*10 + 7;
		if(isprime(result))
			dfs(s+1);
		result = temp*10 + 9;
		if(isprime(result))
			dfs(s+1);
	}
}

int main()
{
	fscanf(in, "%d", &N);
	result = 2;dfs(2);
	result = 3;dfs(2);
	result = 5;dfs(2);
	result = 7;dfs(2);
	return 0;
}