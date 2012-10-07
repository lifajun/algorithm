#include <iostream>
#include <cstring>
using namespace std;

char str[1005][25];

struct Tree
{
	int cnt;
	Tree *next[26];
	Tree()
	{
		cnt = 0;
		memset(next, NULL, sizeof(next));
	}
};

Tree *root = new Tree();

void insert(char *s)
{
	Tree *ptr = root;
	for(unsigned i=0; i<strlen(s); i++)
	{
		int idx = s[i] - 'a';
		if(ptr->next[idx] == NULL)
			ptr->next[idx] = new Tree();
		ptr = ptr->next[idx];
		ptr->cnt++;
	}
}

void search(char *s)
{
	Tree *ptr = root;
	for(unsigned i=0; i<strlen(s); i++)
	{
		printf("%c", s[i]);
		ptr = ptr->next[s[i]-'a'];
		if(ptr->cnt == 1)	break;
	}
	printf("\n");
}

void free(Tree* root)
{
	for(int i=0; i<26; i++)
		if(root->next[i])	
			free(root->next[i]);
	delete root;
}

int main()
{
	int count = 0;
	while(scanf("%s", str[count]) == 1)
	{
		insert(str[count]);
		count++;
	}
	for(int i=0; i<count; i++)
	{
		printf("%s ", str[i]);
		search(str[i]);
	}
	free(root);
	return 0;
}