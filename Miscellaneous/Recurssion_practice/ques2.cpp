/*paths to reach from (0,0)index to (n,m) index in a matrix*/
#include<iostream>
using namespace std;
int paths(int n,int m)
{
    if(n==1 || m==1)      /*base condition*/ /*comming to bottom row or column, only one path to last element*/
    {
        return 1;
    }
    return paths(n,m-1) + paths(n-1,m);   /*we have to move from rest of matrix i.e (n,m-1)or(n-1,m),leaving last row or column*/
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<paths(n,m);    
}
