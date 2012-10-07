/*
ID: lifajun2
PROG: transform
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N;
char start[12][12], end[12][12], temp[12][12], temp2[12][12];

void  op1(char s1[][12], char s2[][12])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			s2[i][j] = s1[N-1-j][i];
	for(int i=0; i<N; i++)	s2[i][N] = '\0';
}

void op2(char s1[][12], char s2[][12])
{
	char tmp[12][12];
	op1(s1, tmp);op1(tmp, s2);
}

void op3(char s1[][12], char s2[][12])
{
	char tmp1[12][12], tmp2[12][12];
	op1(s1, tmp1);op1(tmp1, tmp2);op1(tmp2, s2);
}

void op4(char s1[][12], char s2[][12])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			s2[i][j] = s1[i][N-1-j];
	for(int i=0; i<N; i++)	s2[i][N] = '\0';
}

bool eql(char s1[][12], char s2[][12])
{
	for(int i=0; i<N; i++)
		if(strcmp(s1[i], s2[i]) != 0)	return false;
	return true;
}

int main()
{
	FILE *in = fopen("transform.in", "r");
	FILE *out = fopen("transform.out", "w");
	fscanf(in, "%d", &N);
	for(int i=0; i<N; i++)
		fscanf(in, "%s", start[i]);
	for(int i=0; i<N; i++)
		fscanf(in, "%s", end[i]);

	void (*op[5])(char s1[][12], char s2[][12]);
	op[1] = op1, op[2] = op2, op[3] = op3, op[4] = op4; 
	for(int i=1; i<=4; i++)
	{
		op[i](start, temp);
		if(eql(temp, end))	
		{
			fprintf(out, "%d\n", i);
			return 0;
		}
	}

	op4(start, temp);
	for(int i=1; i<=3; i++)
	{
		op[i](temp, temp2);
		if(eql(temp2, end))
		{
			fprintf(out, "5\n");
			return 0;
		}
	}

	if(eql(start, end))
	{
		fprintf(out,"6\n");
		return 0;
	}

	fprintf(out, "7\n");
	return 0;
}