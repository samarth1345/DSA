#include<iostream>
#include<vector>
using namespace std;
bool searching(vector<int> arr,int num,int key)
{
    for(int i=0;i<num;i++)
    {
        if(arr[i]==key)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int num,key;
    cout<<"Enter size of array and number to find\n";
    cin>>num>>key;
    vector <int> arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    if(searching(arr,num,key))
    {
        cout<<"Number found\n";
    }
    else
    {
        cout<<"Number not found\n";
    }
}