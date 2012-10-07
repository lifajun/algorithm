#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int w;
	int idx;
}arr[8];

int cmp(node n1, node n2)
{
	return n1.w < n2.w;
}

int main()
{
	int w[8] = {100, 200, 50, 90, 150, 50, 20, 80};
	int x[8] = {0};
	int c, count=0;
	for(int i=0; i<8; i++)
		arr[i].w = w[i], arr[i].idx = i;
	cin>>c;
	sort(arr, arr+8, cmp);
	for(int i=0; i<8 && c>=arr[i].w; i++)
	{
		count++;
		c -= arr[i].w;
		x[arr[i].idx] = 1;
	}
	cout<<count<<endl;
	for(int i=0; i<8; i++)	if(x[i])	cout<<i<<" ";
	return 0;
}