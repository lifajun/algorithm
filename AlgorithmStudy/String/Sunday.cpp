#include <iostream>
#include <cstring>
using namespace std;

void pre_sunday(char *pattern, int len, int sunday[])
{
	int i;
	for(i=0; i<256; i++)
		sunday[i] = len + 1;
	while(*pattern != '\0')
		sunday[(unsigned char)*pattern++] = len--;
}

bool mSearch(char *pattern, int len1, char *str, int len2)
{
	int i = 0, j, sunday[256];
	pre_sunday(pattern, len1, sunday);
	while(i<=(len2-len1))
	{
		for(j=0; j<len1 && pattern[j] == str[i+j]; j++);
		if(j == len1)	return true;
		i += sunday[(unsigned char)str[i+len1]];
	}
	return false;
}

int main()
{
	char s1[10000], s2[10000];
	while(scanf("%s%s", s1, s2) != EOF)
	{
		if(mSearch(s1, strlen(s1), s2, strlen(s2)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}