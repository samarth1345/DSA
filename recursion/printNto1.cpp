//program to print n to 1 using recursion
#include<iostream>
using namespace std;
void print(int n)     //hypothesis
{
    if(n==1)          //base condition
    {
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";     //induction
    print(n-1);       //hypothesis
}
int main()
{
    int n;
    cin>>n;
    print(n);
    return 0;
}