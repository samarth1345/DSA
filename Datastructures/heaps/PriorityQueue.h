#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue
{
    vector<int> arr;
    public:
    PriorityQueue(int initialValue)
    {
        arr.push_back(initialValue);
    }
    void swap(int pos1,int pos2)
    {
        int temp=arr[pos1];
        arr[pos1]=arr[pos2];
        arr[pos2]=temp;
    }
    //we will just upHeapify values of array as they are inserted
    //i.e first insert element at end and then compare  with its parent and
    //if it is smaller swap and repeat the previous step
    void Insert(int data)
    {
        arr.push_back(data);
        int index=arr.size()-1;
        while(index>=0 && arr[index]<arr[(index-1)/2])
        {
            swap(index,(index-1)/2);
            index=(index-1)/2;
        }
    }
    //while deleting we have to downHeapify i.e first of all we will swap 
    //the first and last element and remove the last element and then start comparing 
    //the first element with its childrens and swap if it is larger than it's child 
    //keep repeating until child is bigger
    void Delete()
    {
        if(!arr.empty())
        {
            swap(0,arr.size()-1);
            arr.pop_back();
            int child1=1,child2=2,parent=0;
            while(child1<arr.size() || child2<arr.size())
            {
                int temp;
                if(child2<arr.size() && arr[child2]<arr[child1])
                    temp=child2;
                else if(child1<arr.size() && arr[child1]<arr[parent])
                    temp=child1;
                else 
                    break;
                swap(parent,temp);
                parent=temp;
                child1=(2*parent)+1;
                child2=(2*parent)+2;
            }
        }
    }
    int getMin()
    {
        if(arr.size()>0)
            return arr[0];
        return -1;
    }
    void display()
    {
        for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
};