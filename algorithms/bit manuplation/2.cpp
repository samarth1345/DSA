#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	long int t;
	cin>>t;
	while(t--)
	{
	    long int x;
	    cin>>x;
	    long int i=0;
        long int value1=pow(2,i);
        long int value2=value1-1;
	    while((value1|value2)<=x)
	    {
	        i++;
            value1=pow(2,i);
            value2=value1-1;
	    }
	    cout<<value1<<endl;;
	}
	return 0;
}
