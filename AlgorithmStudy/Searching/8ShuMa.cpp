#include <iostream>
#include <cstring>
using namespace std;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}, a[10];
char dir[4] = {'u', 'd', 'l', 'r'};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[500000];

struct Node
{
	int status[10];
	char path[100];
}qu[500000];

int hash(int arr[])
{
	int result = 0, cnt;
	for(int i=0; i<9; i++)
	{
		cnt = 0;
		for(int j=i+1; j<9; j++)
			if(arr[j] < arr[i])	cnt++;
		result += cnt * fact[8-i];
	}
	return result+1;
}

int main()
{
	Node start, end, temp;
	int z, x, y, xx, yy, zz, h, qbegin=0, qend=0;
	char t;

	for(int i=0; i<9; i++)
	{
		end.status[i] = (i+1)%9;
		cin>>t;
		if(t== 'x')	start.status[i] = 0;
		else	start.status[i] = t-'0';
	}
	strcpy(start.path, "");
	memset(vis, false, sizeof(vis));
	vis[hash(start.status)] = true;
	qu[qend++] = start;

	while(qbegin < qend)
	{
		temp = qu[qbegin++];
		if(memcmp(temp.status, end.status, sizeof(int)*9) == 0)
		{
			cout<<temp.path<<endl;
			return 0;
		}
		for(z = 0; z<9; z++)	if(!temp.status[z])	break;
		x = z/3, y = z%3;
		char t_path[100];
		for(int d=0; d<4; d++)
		{
			xx = x + dx[d], yy = y + dy[d], zz = xx*3 + yy;
			memcpy(a, temp.status, sizeof(a));
			strcpy(t_path, temp.path);
			swap(a[z], a[zz]);
			h = hash(a);

			if(xx >= 0 && xx < 3 && yy >=0 && yy < 3 && !vis[h])
			{
				Node _temp;
				char pa[2];
				pa[0] = dir[d], pa[1] = '\0';
				memcpy(_temp.status, a, sizeof(a));
				strcpy(_temp.path, t_path);
				strcat(_temp.path, pa);
				qu[qend++] = _temp;
				vis[h] = true;
			}
		}
	}
	cout<<"unsolvable"<<endl;
	return 0;
}