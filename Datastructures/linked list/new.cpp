#include<iostream>
using namespace std;
int main()
{
    int p=10;
    int *arr;
    arr=&p;
    *(arr-2)=100;
    *(arr-1)=100;
    *(arr+1)=100;
    arr=&p;
    for(int i=-2;i<=1;i++)
    {
        cout<<*(arr+i)<<endl;
    }
}
