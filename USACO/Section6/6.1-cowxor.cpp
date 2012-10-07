/*
ID: lifajun2
PROG: cowxor
LANG: C++
*/
#include <cstdio>
#include <cstring>

int XOR[100005], N, ans = 0, l = 1, r = 1;

struct Node
{
	int idx;
	Node* child[2];
	Node(){memset(child, 0, sizeof(child));}
};

Node *root = new Node;

void insert(int n, int idx)
{
	Node* p = root;
	for(int i=20; i>=0; i--)
	{
		int x = (n & (1<<i)) > 0 ? 1 : 0;
		if(p->child[x] == NULL)
			p->child[x] = new Node;
		p = p->child[x];
	}
	p->idx = idx;
}

void find(int n, int idx)
{
	Node* p = root;
	for(int i=20; i>=0; i--)
	{
		int x = (n & (1<<i)) > 0 ? 1 : 0;
		if(p->child[!x])
			p = p->child[!x];
		else
			p = p->child[x];
	}
	int id = p->idx;
	if((XOR[id] ^ XOR[idx]) > ans)
	{
		ans = XOR[id]^XOR[idx];
		l = id+1, r = idx;
	}
}

int main()
{
	int num;
	FILE* fin = fopen("cowxor.in", "r");
	FILE* fout = fopen("cowxor.out", "w");

	fscanf(fin, "%d", &N);
	XOR[0] = 0;
	insert(0, 0);
	for(int i=1; i<=N; i++)
	{
		fscanf(fin, "%d", &num);
		XOR[i] = XOR[i-1] ^ num;
		find(XOR[i], i);
		insert(XOR[i], i);
	}
	fprintf(fout, "%d %d %d\n", ans, l, r);
	return 0;
}