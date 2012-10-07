#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 5000;

int main()
{
	string buff;
	ifstream infile;
	ofstream outfile;
	infile.open("0.txt");
	string outfilename = ".txt";
	int index = 1;
	int num = 0;
	int all_lines = 0;

	while(getline(infile,buff))
	{
		all_lines++;
		if(num == 0)
		{
			string in = "";
			int copy = index;
			while(copy != 0)
			{
				int digit = copy%10;
				char c = digit + '0';
				in = (char)c + in;
				copy /= 10;
			}
			outfilename = in + outfilename;
			outfile.open(outfilename.c_str());
		}
		outfile<<buff<<endl;
		num++;
		if(num == MAX)
		{
			outfile.close();
			outfilename = ".txt";
			index++;
			num = 0;
		}
	}
	cout<<"All lines: "<<all_lines<<endl;
	infile.close();
	outfile.close();
	return 0;
}