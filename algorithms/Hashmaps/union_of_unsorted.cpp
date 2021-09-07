#include<iostream>
#include<unordered_map>
using namespace std;
int distinct(int* arr1,int* arr2,int size1,int size2)
{
    unordered_map<int,bool> map;
    int ans=0;
    for(int i=0;i<size1;i++)
    {
        if(map[arr1[i]]!=true)
        {
            map[arr1[i]]=true;
            ans++;
        }
    }
    for(int i=0;i<size2;i++)
    {
        if(map[arr2[i]]!=true)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    int size1,size2;
    cin>>size1>>size2;
    int arr1[size1],arr2[size2];
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }
    cout<<distinct(arr1,arr2,size1,size2);
}