#include <iostream>
using namespace std;

void find(int arr[], int n, int result[])
{
	int candidate[3], count[3] = {0};
	for(int i=0; i<n; i++)
	{
		bool flag = false;
		for(int j=0; j<3; j++)
		{
			if(candidate[j] == arr[i])
			{
				count[j]++;
				flag = true;
				break;
			}
		}

		if(flag)	continue;

		flag = false;
		for(int j=0; j<3; j++)
		{
			if(count[j] == 0)
			{
				candidate[j] = arr[i];
				count[j] = 1;
				flag = true;
				break;
			}
		}

		if(flag)	continue;

		for(int j=0; j<3; j++)	count[j]--;
	}

	for(int i=0; i<3; i++)
		result[i] = candidate[i];
}

int main()
{
	int n, arr[100], result[3];
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
			cin>>arr[i];
		find(arr, n, result);
		for(int i=0; i<3; i++)
			cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;
}