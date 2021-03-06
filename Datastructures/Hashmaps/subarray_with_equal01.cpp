#include<iostream>
#include<unordered_map>
using namespace std;
int equal01(int *arr,int size)
{
    unordered_map<int,int> map;
    int temp,max=0,sum=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=-1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (map.count(sum) > 0)
        {
            if (sum == 0)
            {
                map[sum] = i;
            }
            else
            {
                temp = i - map[sum];
                if (temp > max)
                {
                    max = temp;
                }
            }
        }
        else
        {
            map[sum] = i;
        }
    }
    if (map[0] > max)
    {
        max = map[0] + 1;
    }
    return max;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cout << equal01(arr, size)<<endl;
    }
}