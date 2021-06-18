#include<iostream>
#include<vector>
using namespace std;
void swap(int *arr_1, int *arr_2) /*function to swap*/
{
    int temp;
    temp=*arr_1;
    *arr_1=*arr_2;
    *arr_2=temp;
}
void sort(vector<int> &arr,int start,int end)
{
    if(start<end-1)
    {
    int pivot,i=start,j=start;   /*setting i and j at same position(not as done)*/
    pivot=end-1;                 /*pivot is a element to compare with other elements*/
    while(j<pivot)               /*this loop is to set pivot at its right pos.*/
    {
        if(arr[j]<arr[pivot])
        {
            swap(&arr[j],&arr[i]);
            i++;
        }
        j++;
    }
    swap(&arr[i],&arr[pivot]);       /*final swap to put pivot at pos*/
    sort(arr,start,i);               /*sorting array before pivot by recurssion*/
    sort(arr,i+1,end);               /*sorting array after pivot by recurssion*/
    }

}
void display(vector<int> arr, int num)
{
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }

}
int main()
{
    int num;
    cin>>num;
    vector<int> arr;
    for(int i=0;i<num;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr,0,num);
    display(arr,num);      /*to display sorted array*/
    return 0;
}