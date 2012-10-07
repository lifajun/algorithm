/*
ID: lifajun2
PROG: msquare
LANG: C++
*/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040};
bool vis[50000];

struct Node
{
	char path[1000];
	int status[8];
};

bool equalNode(Node a, Node b)
{
	for(int i=0; i<7; i++)
		if(a.status[i] != b.status[i])
			return false;
	return true;
}

void A(int status[])
{
	int l = 0, r = 7;
	while(l < r)
		swap(status[l++], status[r--]);
}

void B(int status[])
{
	int x = status[3];
	for(int i=3; i>0; i--)
		status[i] = status[i-1];
	status[0] = x;
	x = status[4];
	for(int i=4; i<7; i++)
		status[i] = status[i+1];
	status[7] = x;
}

void C(int status[])
{
	int x1 = status[1], x2 = status[2], x3 = status[5], x4 = status[6];
	status[1] = x4, status[2] = x1, status[5] = x2, status[6] = x3;
}

int hash(int status[])
{
	int res = 0;
	for(int i=0; i<7; i++)
	{
		int cnt = 0;
		for(int j=i+1; j<8; j++)
			if(status[j] < status[i])
				cnt++;
		res += cnt*fact[7-i];
	}
	return res;
}

int main()
{
	FILE* in = fopen("msquare.in", "r");
	FILE* out = fopen("msquare.out", "w");
	
	Node start, end;
	for(int i=0; i<8; i++)
	{
		fscanf(in, "%d", &end.status[i]);
		start.status[i] = i+1;
	}
	strcpy(start.path, "");
	queue<Node> q;
	q.push(start);
	memset(vis, false, sizeof(vis));
	vis[0] = true;
	void (*op[3])(int status[]);
	op[0] = A, op[1] = B, op[2] = C; 

	while(!q.empty())
	{
		Node temp = q.front(); q.pop();
		if(equalNode(temp, end))
		{
			fprintf(out, "%d\n%s\n", strlen(temp.path), temp.path);
			return 0;
		}

		for(int i=0; i<3; i++)
		{
			Node temp1 = temp;
			int hashcode;
			char pt[2];

			op[i](temp1.status);
			hashcode = hash(temp1.status);
			if(!vis[hashcode])
			{
				vis[hashcode] = true;
				pt[0] = (char)('A' + i), pt[1] = '\0';
				strcat(temp1.path, pt);
				q.push(temp1);
			}
		}
	}
	return 0;
}