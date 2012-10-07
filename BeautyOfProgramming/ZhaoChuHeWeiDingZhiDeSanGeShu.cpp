#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[100], n, m;
	while(cin>>n, n)
	{
		for(int i=0; i<n; i++)
			cin>>arr[i];
		cin>>m;
		sort(arr, arr+n);
		int i , j, k;
		for(k=0; k<n; k++)
		{
			int subsum = m - arr[k];
			i = 0, j = n-1;
			while(i < j)
			{
				if(i == k)	{i++;continue;}
				if(j == k)	{j--;continue;}
				int temp = arr[i] + arr[j];
				if(temp < subsum)	i++;
				else if(temp > subsum)	j--;
				else	{cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;i++;j--;}
			}
		}
	}
	return 0;
}