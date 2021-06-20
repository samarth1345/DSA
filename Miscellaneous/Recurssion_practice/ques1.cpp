/*https://practice.geeksforgeeks.org/problems/geek-onacci-number/0/?difficulty[]=0&amp;page=1&amp;category[]=Recursion&amp;query=difficulty[]0page1category[]Recursion#*/
#include <iostream>
using namespace std;
int onacci(int num,int a,int b,int c)
{
	 if(num==1)
	 {
	     return a;
	 }
	 if(num==2)
	 {
	      return b;
	 }
	 if(num==3)
	 {
	      return c;
	 }
	 return onacci(num-1,a,b,c)+onacci(num-2,a,b,c)+onacci(num-3,a,b,c);
	        
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b,c,n;
	    cin>>a>>b>>c>>n;
	    cout<<onacci(n,a,b,c)<<endl;
	}
	return 0;
}