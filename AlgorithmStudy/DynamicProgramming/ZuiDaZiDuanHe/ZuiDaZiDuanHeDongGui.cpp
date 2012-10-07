#include <iostream>
#include <cstdlib>
using namespace std;

//利用一个辅助数组b[]，b[i]保存的是以第i个数结尾时的最大子段和。
//在求第i个数是否包含在最大子段和中时，如果b[i-1]>0时，b[i] = b[i-1] + a[i]，
//否则b[i] = a[i]，用动态规划表示b[i] = max(b[i-1] + a[i], a[i])

//int main()
//{
//	int a[100], b[100] = {0}, n, max = 0;
//	cin>>n;
//	for(int i=1; i<=n; i++)
//		cin>>a[i];
//	for(int i=1; i<=n; i++)
//	{
//		b[i] = b[i-1] + a[i];
//		if(a[i] > b[i])	b[i] = a[i];
//		if(b[i] > max)	max = b[i];
//	}
//	cout<<max<<endl;
//}

/*int main()
{
	int val, b = 0, n, max = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>val;
		b += val;
		if(val > b)	b = val;
		if(b > max)	max = b;
	}
	cout<<max<<endl;
	return 0;
}*/

//f[a, b] = max(f[a, b-1] + arr[b], f[b-f+1, b])

int main()
{
	int a[100], b[100], n, max = INT_MIN, m, cur, pre;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		b[i] = b[i-1] + a[i];
	}
	pre = b[m-1] - b[0];
	for(int i=m; i<=n; i++)
	{
		cur = b[i] - b[i-m];
		pre = pre + b[i];
		if(cur > pre)	pre = cur;
		if(pre > max)	max = pre;
	}
	return 0;
}