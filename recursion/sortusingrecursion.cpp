//sorting using recursion
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>& arr,int temp)
{
    if(arr.size()==0 || arr[arr.size()-1]<=temp)        //base condition
    {
        arr.push_back(temp);
        return;
    }
    int store=arr[arr.size()-1];
    arr.pop_back();                   //taking out the last element till base condition is not satisfied
    insert(arr,temp);
    arr.push_back(store);              //inserting the last elemnts a last as they are larger than "temp"
}
void sort(vector<int>& arr)
{
    if(arr.size()==1)                 //base condition: if size is 1 array is already sorted
    {
        return;
    }
    int val=arr[arr.size()-1];    //storing last element so that all elements before this can be sorted
    arr.pop_back();
    sort(arr);                    //24 and 25 line as a whole is hypothesis as we are sorting elements leaving the last
    insert(arr,val);                 //induction: inserting the popped out element at right place
}
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
