#include<bits/stdc++.h>
using namespace std;
bool searching(vector<int> arr,int num,int key)
{
    sort(arr.begin(),arr.end());
    int start=0;
    int end=num;
    int mid;
    while(start<=end)
    {
        mid=(end-(start+end)/2);
        if(key==arr[mid])
        {
            return true;
        }
        else if(key<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return false;
}
int main()
{
    int num,key;
    cout<<"Enter size of array and number to find\n";
    cin>>num>>key;
    vector <int> arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    if(searching(arr,num,key))
    {
        cout<<"Number found\n";
    }
    else
    {
        cout<<"Number not found\n";
    }
}
