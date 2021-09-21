#include <iostream>
#include <unordered_map>
using namespace std;
int solve(int *arr,int size)
{
    unordered_map<int,int> map;
    int sum=0,count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            count++;
        }
        sum+=arr[i];
        if(sum==0 || map[sum]>0)
        {
            if(i>0 && map[sum]>0 )
            {
                count+=map[sum];
            }
            else if(arr[i-1]==0)
            count++;
        }
        map[sum]++;
    }
    return count;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,size)<<endl;
}