//find distinct element in every window of size k
#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;
vector<int> solve(int *arr, int size,int k)
{
    vector<int> v;
    //map to store element and its frequency window wise
    unordered_map<int,int> map;
    bool flag=false;
    for(int i=0;i<size;i++)
    {
        //cout<<map.size()<<endl;
        if(flag)
        {
            map[arr[i-k]]--;         //reducing frequency of element outside window
            if(map[arr[i-k]]==0)     //if frequency becomes zero we remove element from map
            {
                map.erase(arr[i-k]);
            }
        }
        map[arr[i]]++;     //increasing frequency of element
        if((i+1)>=k)
        {
            v.push_back(map.size());  //storing distinct elements of every window
            flag=true;
        }
    }
    return v;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin>>k;
        vector<int> ans=solve(arr,size,k);
        while(ans.size()>0)
        {
            cout<<ans.front()<<" ";
            ans.erase(ans.begin());
        }
        cout<<endl;
    }
}