#include <bits/stdc++.h>
using namespace std;
//logic:this is just a slight modification for first_last_occurence 
//if we get the first last index of element 
//we have to just subtract last from first and  add 1.
int occurences(vector<int> &arr, int x)
{
    vector<int> ans;
    int start = 0, end = arr.size()-1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            if (ans.size()==0)
                ans.push_back(mid);
            else
            {
                ans.erase(ans.begin());
                ans.push_back(mid);
            }
            end = mid - 1;
        }
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (ans.empty())
    {
        return 0;
    }
    start = 0;
    end = arr.size()-1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            if (ans.size() == 1)
                ans.push_back(mid);
            else
            {
                ans.erase(ans.begin() + 1);
                ans.push_back(mid);
            }
            start = mid + 1;
        }
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return ans[1]-ans[0]+1;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout << occurences(arr, x) << endl;
}