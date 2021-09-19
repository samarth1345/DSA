/*O(n^2)=worst case    : when array is sorted partition is done at beginning or end
  O(nlog(n))=best case : when partition is done in mid leading to dec. in tree size
  O(n^2)=average case*/
#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void quicksort(int arr[],int start,int end)
{
    int n=start-end;
    if(n==0 || n==1)
    {
        return;
    }
    int pi,i,j;
    pi=end-1;
    i=start;
    j=start;
    while(j<end)
    {
        if(arr[j]<arr[pi])
        {
            swap(arr,i,j);
            i++;
        }
        j++;
    }
    swap(arr,pi,i);
    quicksort(arr,start,i);
    quicksort(arr,i+1,end);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}