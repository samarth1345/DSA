/*insertion sort-this takes a element at a time traverse back to 0 pos. while comparing the elements and swapping*/
#include<iostream>
using namespace std;
/*function to sort the unsorted array*/
void sort(int arr[],int num)
{
    for(int i=1;i<num;i++)
    {
        int current=arr[i];    /*initialising current element*/
        int j=i-1;
        while(j>=0 && current<arr[j])    /*traversing back from i position to 0 pos*/
        {
            if(arr[j]>current)
            {
                arr[j+1]=arr[j];
                arr[j]=current;
            }
            j--;
        }
    }
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    sort(arr,num);
}