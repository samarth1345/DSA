//More than n/k Occurences
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int *arr, int size, int k)
{
    unordered_map<int, int> map;
    vector<int> v;
    int help = (size + 1) / k;
    for (int i = 0; i < size; i++)
    {
        //once no has been added to vector we 
        //don't need to add that again: reason for below if cond
        if (map[arr[i]] != -1)
        {
            map[arr[i]]++;
        }
        if (map[arr[i]] > help)
        {
            map[arr[i]] = -1;
            v.push_back(arr[i]);
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
        cin >> k;
        vector<int> ans=solve(arr, size, k);
        while(ans.size()>0)
        {
            cout<<ans.front()<<" ";
            ans.erase(ans.begin());
        }
        cout<<endl;
    }
}