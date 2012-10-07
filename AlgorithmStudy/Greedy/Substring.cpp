#include <iostream>
#include <string>
using namespace std;

string str[10];
int main()
{
    int n, T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>str[i];
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(str[i] + str[j] > str[j] + str[i])
                    swap(str[i], str[j]);
        for(int i=0; i<n; i++)
            cout<<str[i];
        cout<<endl;
    }
    return 0;
}