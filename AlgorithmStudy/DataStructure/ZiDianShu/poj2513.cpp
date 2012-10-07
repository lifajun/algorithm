#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500004

int degree[MAX], father[MAX];
int color;

struct TreeNode
{
	bool flag;
	int id;
	TreeNode *children[26];
	TreeNode()
	{
		flag = false, id =0;
		memset(children, 0, sizeof(children));
	}
};//字典树节点

TreeNode *root = new TreeNode();

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}//并查集压缩路径

//通过字典树把字符串映射为整数
int hash(char *str)
{
	TreeNode *ptr = root;
	for(unsigned i=0; i<strlen(str); i++)
	{
		int idx = str[i]-'a';
		if(!ptr->children[idx])
			ptr->children[idx] = new TreeNode;
		ptr = ptr->children[idx];
	}
	if(!ptr->flag)
	{
		ptr->flag = true;
		ptr->id = ++color;
	}
	return ptr->id;
}

/*void Free(TreeNode* root)
{
	for(int i=0; i<26; i++)
		if(root->children[i])
			free(root->children[i]);
	delete root;
}*/

int main()
{
	color = 0;
	char first[11], second[11];
	for(int i=1; i<=MAX; i++)
		father[i] = i;
	memset(degree, 0, sizeof(degree));
	while(cin>>first>>second)
	{
		int x = hash(first), y = hash(second);
		degree[x]++, degree[y]++;
		int f1 = find(x), f2 = find(y);
		father[f1] = f2;
	}
	int s = find(1);
	int num = 0;//度数为奇的点的个数
	for(int i=1; i<=color; i++)
	{
		if(degree[i] % 2)
			num++;
		if(num > 2 || find(i) != s)
		{
			cout<<"Impossible"<<endl;
			//Free(root);
			return 0;
		}
	}
	if(num == 1)
		cout<<"Impossible"<<endl;
	else
		cout<<"Possible"<<endl;
	//Free(root);
	return 0;
}