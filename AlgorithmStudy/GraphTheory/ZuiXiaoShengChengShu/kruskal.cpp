#include <iostream>
#include <algorithm>
using namespace std;

int father[1000], n, m;

struct Edge
{
	int u, v, w;
	Edge(){}
	Edge(int uu, int vv, int ww){u = uu, v = vv, w = ww;}
}E[1000];

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}
int cmp(Edge e1, Edge e2){return e1.w < e2.w;}

int kruskal()
{
	int ans = 0;
	for(int i=1; i<=n; i++)	father[i] = i;
	sort(E, E+m, cmp);
	for(int i=0; i<m; i++)
	{
		int f1 = find(E[i].u),  f2 = find(E[i].v);
		if(f1 != f2)
		{
			ans += E[i].w;
			father[f1] = f2;
		}
	}
	return ans;
}

int main()
{
	cin>>n;
	m = 0;
	int w;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>w;
			if(i != j)
				E[m++] = Edge(i, j, w);
		}
	}
	cout<<kruskal()<<endl;
	return 0;
}