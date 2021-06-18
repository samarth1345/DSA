#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool searching(vector<int> arr,int num,int key)
{
    int jump=pow(num,1/2);
    int current=jump;
    int prev=0;
    while(jump<=num)
    {
        if(arr[current]==key)
        {
            return true;
        }
        else if(key<arr[current])
        {
            for(int i=prev;i<current;i++)
            {
                if(arr[i]==key)
                {
                    return true;
                }
            }
            return false;
        }
        prev=current;
        current+=jump;
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