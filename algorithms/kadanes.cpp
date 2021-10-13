//maximum subarray sum by kadanes algorithm
#include<iostream>
using namespace std;
int kadane(int *nums,int size)
{
    int sum=nums[0];
    int max=sum;
    for(int i=1;i<size;i++)
    {
        if(sum<0)
        {
            sum=0;
        }
        sum+=nums[i];
        if(sum>max)
        {
            max=sum;
        }
    }
    return max;
}
int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<kadane(nums,n);
}