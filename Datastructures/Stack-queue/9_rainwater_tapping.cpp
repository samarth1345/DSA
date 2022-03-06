#include<bits/stdc++.h>
using namespace std;
//function to return max elements to right of each element in heightay
vector<int> MAXR(int height[],int size)
{
    vector<int> maxr(size);
    maxr[size-1]=height[size-1];
    for(int i=size-2;i>=0;i--)
    {
        maxr[i]=max(maxr[i+1],height[i]);
    }
    return maxr;
}  
//function to return max elements to left of each element in heightay
vector<int> MAXL(int height[],int size)
{
    vector<int> maxl(size);
    maxl[0]=height[0];
    for(int i=1;i<size;i++)
    {
        maxl[i]=max(maxl[i-1],height[i]);
    }
    return maxl;
} 
int solve(int height[],int size)
{
    vector<int> maxr;
    vector<int> maxl;
    maxr=MAXR(height,size);
    maxl=MAXL(height,size);
    int water[size];
    for(int i=0;i<size;i++)
    {
        water[i]=((min(maxr[i],maxl[i]))-height[i]);         //calculating water that can be stored on top each element(take as stack)
    }
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans+=water[i];                                    //adding total water stored
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int height[n];
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    cout<<solve(height,n);
    return 0;
}