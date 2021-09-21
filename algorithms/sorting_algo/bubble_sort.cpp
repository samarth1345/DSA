/*BUBBLE SORT-Taking adjacent elements,swapping if required*/
/*O(n^2)=worst case
  O(n)=best case : if array is already sorted
  O(n^2)=average case*/
#include<iostream>
using namespace std;
/*function to swap array elemments*/

void swap(int *arr_1, int *arr_2)
{
    int temp;
    temp=*arr_1;
    *arr_1=*arr_2;
    *arr_2=temp;
}

/*function to sort unsorted array*/

int sort(int arr[],int num)     /*At end of 1st loop of "i",largest element of array would be at last position*/
{
    bool flag=false;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num-i;j++)
        {
            if(arr[j]>arr[j+1])          /*comparing adjacent elements and swapping if required*/
            {
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag)
        {
            break;
        }
    }
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
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
    return 0;
}
