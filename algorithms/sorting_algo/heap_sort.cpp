#include <bits/stdc++.h>
using namespace std;
//Implemented using max heap
void swap(int*arr,int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
//Upheapify similar to PriorityQueue.h
//only change is that we were using extra O(n) space in it, but we are not going 
//to use it int this,we will use the given array to behave like extra space.
//we will start with size 1 and let Insert function to work on it and then
//increase size gradually to full capacity to give an illusion of inserting elements 
//in new array
void Insert(int data, int *arr, int size)
{
    arr[size] = data;
    int index = size;
    while (index >= 0 && arr[index] > arr[(index - 1) / 2])
    {
        swap(arr,index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
//Downheapify similar to PriorityQueue.h
//similarily,we will delete first element but not permanentily,we will just decrease the
//size of the array,and not change the elements once they have been deleted(size decreased).
void Delete(int *arr,int size)
{
    swap(arr,0, size - 1);
    size=size-1;
    int child1 = 1, child2 = 2, parent = 0;
    while (child1 < size || child2 < size)
    {
        int temp;
        if (child2 < size && arr[child2] > arr[child1])
            temp = child2;
        else if (child1 < size && arr[child1] > arr[parent])
            temp = child1;
        else
            break;
        swap(arr,parent, temp);
        parent = temp;
        child1 = (2 * parent) + 1;
        child2 = (2 * parent) + 2;
    }
}
void heapsort(int *arr, int size)
{
    for(int i=1;i<size;i++)
    Insert(arr[i],arr,i);

    for(int i=1;i<size;i++)
    Delete(arr,size-i+1);
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}