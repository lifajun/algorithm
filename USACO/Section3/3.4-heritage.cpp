/*
ID: lifajun2
PROG: heritage
LANG: C++
*/
#include <cstdio>
#include <cstring>

char in[30], pre[30], post[30];

int find(char* str, char c)
{
	for(int i=0; i<strlen(str); i++)
		if(str[i] == c)	return i;
	return -1;
}

void heri(char* in, char* pre, char* post, int len)
{
	if(len == 0)	return;
	int idx = find(in, pre[0]);
	heri(in, pre+1,post, idx);
	heri(in+idx+1, pre+idx+1, post+idx, len - idx -1);
	post[len-1] = pre[0];
}

int main()
{
	FILE* infile = fopen("heritage.in", "r");
	FILE* outfile = fopen("heritage.out", "w");

	fgets(in, 30, infile);
	fgets(pre, 30, infile);

	int len = strlen(in);
	in[len-1] = '\0',pre[len-1] = '\0';
	len--;
	heri(in, pre, post, len);
	post[len] = '\0';

	fprintf(outfile, "%s\n", post);
	return 0;
}