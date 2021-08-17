#include<bits/stdc++.h>
using namespace std;
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int start,end,mid;
    start=0;
    end=n;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==x)
        {
            if(ans.size()==0)
            {
                ans.push_back(mid);
            }
            else
            {
                ans.pop_back();
                ans.push_back(mid);
            }
            end=mid-1;
        }
        else if(arr[mid]>x)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    start=0;
    end=n;
    if(ans.size()==0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==x)
            {
                if(ans.size()==1)
                {
                    ans.push_back(mid);
                }
                else
                {
                    ans.pop_back();
                    ans.push_back(mid);
                }
                start=mid+1;
            }
            else if(arr[mid]>x)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
    }
    return ans;
}
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans;
    ans=find(arr,n,x);
    cout<<ans[0]<<endl<<ans[1];
}