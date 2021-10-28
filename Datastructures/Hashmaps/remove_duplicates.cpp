#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> remove_duplicates(int *arr,int size)
{
    unordered_map<int,bool> map;
    vector<int> v;
    for(int i=0;i<size;i++)
    {
        if(map[arr[i]] != true)
        {
            v.push_back(arr[i]);
            map[arr[i]]=true;
        }
    }
    return v;
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
    vector<int> ans=remove_duplicates(arr,size);
    while(ans.size())
    {
        cout<<ans.front()<<" ";
        ans.erase(ans.begin());
    }
}