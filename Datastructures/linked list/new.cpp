#include<iostream>
using namespace std;
int main()
{
    int arr[6]={1,2,3,4,100,100,1};
    int ans=0;
    for(int i=0;i<6;i++)
    {
        ans=ans^arr[i];
    }
    cout<<ans<<endl;
}
