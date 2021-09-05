#include<iostream>
#include<unordered_map>
using namespace std;
int pair_with_diff(int *arr,int size,int k)
{
    int count=0;
    unordered_map<int,int> map;
    for(int i=0;i<size;i++)
    {
        if(map[arr[i]]>0)
        {
            map[arr[i]]=map[arr[i]]+1;
        }
        else
        {
            map[arr[i]]=1;
        }
    }
    for(int i=0;i<size;i++)
    {
        int help;
        if(arr[i]>0)
        {
            help=arr[i]+k;
        }
        else
        {
            help=arr[i]-k;
        }
        if(map[help]>0)
        {
            map[arr[i]]=map[arr[i]]-1;
            if(map[help]>1)
            {
                count+=map[arr[i]+k];
            }
            else if(map[help])
            {
                count++;
            }
        }
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
    int k;
    cin>>k;
    cout<<pair_with_diff(arr,size,k);
}