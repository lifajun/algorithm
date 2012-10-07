#include <iostream>
#include <cmath>
#include <string>
using namespace std;

__int64 gcd(__int64 a, __int64 b){return b == 0 ? a : gcd(b, a%b);}

int main()
{
	string input;
	while(cin>>input)
	{
		string a_str, b_str;
		int idx1 = input.find('('), idx2 = input.find(')');

		a_str = input.substr(2, idx1 - 2);
		b_str = input.substr(idx1 + 1, idx2 - idx1 - 1);

		__int64 a = atoi(a_str.c_str()), b = atoi(b_str.c_str());
		int a_len = a_str.length(), b_len = b_str.length();

		__int64 fenzi = a * (pow(10.0, (double)b_len) - 1) + b;
		__int64 fenmu = pow(10.0, (double)a_len) * (pow(10.0, (double)b_len) - 1);

		__int64 g = gcd(fenzi, fenmu);
		cout<<"X = "<<fenzi/g<<"/"<<fenmu/g<<endl;
	}
	return 0;
}