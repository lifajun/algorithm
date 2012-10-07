#include <iostream>
using namespace std;

int main()
{
	int arr[1000], n, min, max;
	while(cin>>n, n)
	{
		for(int i=0; i<n; i++)
			cin>>arr[i];
		if(n & 1)	arr[n] = arr[0];

		if(arr[0] > arr[1])
			max = arr[0], min = arr[1];
		else
			max = arr[1], min = arr[0];

		for(int i=2; i<n; i+=2)
		{
			if(arr[i] > arr[i+1])
			{
				if(arr[i] > max)	max = arr[i];
				if(arr[i+1] < min)	min = arr[i+1];
			}
			else
			{
				if(arr[i+1] > max)	max = arr[i+1];
				if(arr[i] < min)	min = arr[i];
			}
		}
		cout<<max<<" "<<min<<endl;
	}
	return 0;
}