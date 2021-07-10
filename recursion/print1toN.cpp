//print 1 to n using recursion
#include<iostream>
using namespace std;
void print(int n)     //hypothesis
{
    if(n==1)          //base condition
    {
        cout<<n<<" ";
        return;
    }
    print(n-1);       //hypothesis
    cout<<n<<" ";     //induction
}
int main()
{
    int n;
    cin>>n;
    print(n);
    return 0;
}