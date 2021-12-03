#include<bits/stdc++.h>
using namespace std;
//logic:this is not a direct problem of binary search,we will apply binary search
//but not on given data,we will apply BS on Answer i.e maximum number of pages
//first of all we need to find bracket(limits) for maximum no. of pages.
//lower limit will be max value in array and upper limit will be sum of all no..
//check function will check that for given max books can we distribute them
//among same no. of students as required and we will move start and end accordingly.
bool check(int *A, int N, int K,int M)
{
    int temp = 0, j = 1;
    for (int i = 0; i < N; i++)
    {
        temp += A[i];
        if (temp > K)
        {
            j++;
            temp = A[i];
        }
        if(j>M)
        return false;
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    int maxi = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        maxi = max(maxi, A[i]);
    }
    int start = maxi, end = sum, mid, ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (check(A,N,mid,M))
        {
            end = mid - 1;
            ans = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int N,M;
    cin>>N>>M;
    int A[N];
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<findPages(A,N,M);
}