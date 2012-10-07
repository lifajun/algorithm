#include <iostream>
using namespace std;

int main()
{
	int arr[100], n;
	while(cin>>n, n)
	{
		int max, secmax;
		for(int i=0; i<n; i++)
			cin>>arr[i];

		if(arr[0] < arr[1])	max = arr[1], secmax = arr[0];
		else	max = arr[0], secmax = arr[1];

		for(int i=2; i<n; i++)
		{
			if(arr[i] > max)
				secmax = max, max = arr[i];
			else if(arr[i] > secmax && arr[i] != max)
				secmax = arr[i];
		}

		cout<<secmax<<endl;
	}
	return 0;
}