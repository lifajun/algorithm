/*
ID: lifajun2
PROG: zerosum
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int sum, last, N;
FILE* in = fopen("zerosum.in", "r");
FILE* out = fopen("zerosum.out", "w");
char str[30];

void dfs(int s)
{
	if(s > N)
	{
		if(sum == 0)
			fprintf(out, "%s\n", str);
		return;
	}
	char temp[30], tt[5];
	int cpy_sum = sum;
	strcpy(temp, str);
	sprintf(tt, "%d", s);
		
	if(last > 0)
		sum = cpy_sum - last + last*10 + s, last = last*10 + s;
	else
		sum = cpy_sum - last + last*10 - s, last = last*10 - s;
	strcpy(str, temp);strcat(str," ");	strcat(str, tt); 
	dfs(s+1);

	strcpy(str, temp);strcat(str,"+");	strcat(str, tt); 
	sum = cpy_sum + s, last = s;
	dfs(s+1);

	strcpy(str, temp);strcat(str,"-");	strcat(str, tt); 
	sum = cpy_sum - s, last = -s;
	dfs(s+1);
}

int main()
{
	fscanf(in, "%d", &N);
	sum = 1, last = 1;
	strcpy(str, "1");
	dfs(2);
	return 0;
}