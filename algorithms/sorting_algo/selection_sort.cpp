/*INSERTION SORTING*/

/* Basic way of sorting arrays*/
#include <iostream>
using namespace std;

/*function to swap*/

void swap(int *arr_1,int *arr_2)
{
    *arr_1=*arr_1^*arr_2;
    *arr_2=*arr_1^*arr_2;
    *arr_1=*arr_1^*arr_2;
}

/*function to sort the unsorted array*/

void sort(int arr[],int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[j]<arr[i])
            {
                swap(&arr[j],&arr[i]);
            }
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
    sort(arr, num);
    return 0;
}