#include <bits/stdc++.h>
using namespace std;
void findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (pq.size() < k)
            pq.push(arr[i]);
        else
        {
            if (abs(x - pq.top()) > abs(x - arr[i]))
            {
                pq.pop();
                pq.push(arr[i]);
            }
            else if (arr[i] == pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
            else
                break;
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main()
{
    int size,k,x;
    cin>>size>>k>>x;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
        cin>>nums[i];
    findClosestElements(nums,k,x);
}