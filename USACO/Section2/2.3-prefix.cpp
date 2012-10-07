/*
ID: lifajun2
PROG: prefix
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

char primitives[205][15], temp[15];
char str[200005], lin[80];
bool dp[200005];
int pri_cnt = 0;

bool found(char* s)
{
	int l = 0, r = pri_cnt, mid;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(strcmp(primitives[mid], s) == 0)
			return true;
		else if(strcmp(primitives[mid], s) < 0)
			l = mid + 1;
		else r = mid - 1;
	}
	return false;
}

int comp(const void *a,const void *b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	int len = 0, len_s;
	FILE* in = fopen("prefix.in", "r");
	FILE *out = fopen("prefix.out", "w");

	while(fscanf(in, "%s", primitives[pri_cnt]) == 1)
	{
		if(strcmp(primitives[pri_cnt], ".") == 0)
		{pri_cnt--; break;}
		else	pri_cnt++;
	}

	fgetc(in);
	while(fgets(lin, 80, in))
	{
		len_s = strlen(lin) - 1;
		strncat(str+1, lin, len_s);
		len += len_s;
	}
	str[++len] = lin[len_s];

	qsort(primitives, pri_cnt+1, sizeof(primitives[0]), comp);
	memset(dp, false, sizeof(dp));
	dp[0] = true;

	for(int i=1; i<=len; i++)
	{
		bool flag = false;
		for(int j=1; j<=10 && i-j >= 0; j++)
		{
			char tmp[15];
			strncpy(tmp, str+i-j+1, j);
			tmp[j] = '\0';
			if(dp[i-j] && found(tmp))
				flag = true;
			if(flag)	break;
		}
		dp[i] = flag;
	}

	for(int i=len; i>=0; i--)
		if(dp[i])	
		{
			fprintf(out, "%d\n", i);
			return 0;
		}
	return 0;
}