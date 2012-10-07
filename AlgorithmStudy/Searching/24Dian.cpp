#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double arr[4];

bool dfs(int n)
{
	if(n == 1)
		return abs(arr[0] - 24) <= 0.000001;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			double a = arr[i], b = arr[j];
			arr[j] = arr[n-1];

			arr[i] = a + b;
			if(dfs(n-1))
				return true;

			arr[i] = a - b;
			if(dfs(n-1))
				return true;

			arr[i] = b - a;
			if(dfs(n-1))
				return true;

			arr[i] = a * b;
			if(dfs(n-1))
				return true;

			if(a)
			{
				arr[i] = b / a;
				if(dfs(n-1))
					return true;
			}

			if(b)
			{
				arr[i] = a / b;
				if(dfs(n-1))
					return true;
			}

			arr[i] = a, arr[j] = b;
		}
	}
	return false;
}

int main()
{
	string c;
	for(int i=0; i<4; i++)
	{
		cin>>c;
		if(c == "A")
			arr[i] = 1;
		else if(c == "J")
			arr[i] = 11;
		else if(c == "Q")
			arr[i] = 12;
		else if(c == "K")
			arr[i] = 13;
		else
			arr[i] = atoi(c.c_str());
	}
	if(dfs(4))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}