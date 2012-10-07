#include <stdio.h>
#include <string.h>

char s1[100005], s2[100005];

int main()
{
	int len1, len2, i, j;
	while(scanf("%s%s", s1, s2) != EOF)
	{
		len1 = strlen(s1), len2 = strlen(s2);
		j = 0;
		for(i=0; i<len2; i++)
		{
			if(s2[i] == s1[j])
				j++;
		}
		printf("%s\n", (j == len1) ? "Yes" : "No");
	}
	return 0;
}