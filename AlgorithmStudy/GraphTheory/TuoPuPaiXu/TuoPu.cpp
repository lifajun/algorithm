#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool G[50][50];
int n;

bool TopSort(vector<int>& v)
{
	int in_degree[50];
	memset(in_degree, 0, sizeof(in_degree));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(G[i][j])	in_degree[j]++;

	for(int i=1; i<=n; i++)
	{
		int j;
		for(j=1; j<=n; j++)
			if(in_degree[j] == 0)	break;
		if(j > n)	return false;
		v.push_back(j);
		in_degree[j] = -1;
		for(int k=1; k<=n; k++)
			if(G[j][k])	in_degree[k]--;
	}
	return false;
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>G[i][j];
	vector<int> v;
	if(TopSort(v))
	{
		for(unsigned i=0; i<v.size(); i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"has circle"<<endl;

	return 0;
}