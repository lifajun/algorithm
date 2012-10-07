/*
ID: lifajun2
PROG: calfflac
LANG: C++
*/
#include <cstdio>
#include <cstring>

char str[20005], tmp[85], pre[20005];
int pos[20005], cnt = 0;

int main()
{
	FILE* in = fopen("calfflac.in", "r");
	FILE* out = fopen("calfflac.out", "w");
	int max, st, en;
	
	while(fgets(tmp, 85, in))
		strcat(str, tmp);
	for(unsigned i=0; i<strlen(str); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z') {pre[cnt] = str[i], pos[cnt++] = i;}
		if(str[i] >= 'A' && str[i] <= 'Z') {pre[cnt] = (char)(str[i] + 32); pos[cnt++] = i;}
	}

	max = 1, st = pos[0], en = pos[0];
	for(int i=0; i<cnt; i++)
	{
		int j;
		for(j=1; i-j>=0 && i+j<cnt && pre[i-j] == pre[i+j]; j++);
		if(2*j -1 > max){max = 2*j -1, st = pos[i-j+1], en = pos[i+j-1];}
		if(i+1 < cnt && pre[i] == pre[i+1])
		{
			for(j=1; i-j>=0 && i+1+j < cnt && pre[i-j] == pre[i+1+j]; j++);
			if(2*j > max){max = 2*j, st = pos[i-j+1], en = pos[i+j];}
		}
	}

	fprintf(out, "%d\n", max);
	for(int i=st; i<=en; i++)
		fprintf(out, "%c", str[i]);
	fprintf(out, "\n");

	return 0;
}