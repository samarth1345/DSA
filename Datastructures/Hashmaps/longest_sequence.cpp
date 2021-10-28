#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> sequence(int *arr, int size)
{
    unordered_map<int, bool> map;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]] = true;
    }
    int head, tail, count, max = 0;
    for (int i = 0; i < size; i++)
    {
        int new_head, new_tail;
        count = 0;
        if (map[arr[i]])
        {
            count++; //count for arr[i] has been included
            int j, k;
            new_head = new_tail =arr[i];
            if (map[arr[i] - 1]) //if arr[i]-1 is present in array
            {
                j = arr[i] - 1;
            }
            if (map[arr[i] + 1]) //if arr[i]+1 is present in array
            {
                k = arr[i] + 1;
            }
            while (map[j])       //checking for numbers less than arr[i]
            {
                new_tail = j;
                count++;
                map[j] = false;  //if present make them false so that they are not included in some other sequence
                j--;
            }
            while (map[k])        //checking for numbers more than arr[i]
            {
                new_head = k;
                count++;
                map[k] = false;
                k++;
            }
        }
        if (count >= max)     //if larger sequence is found
        {
            head = new_head;
            tail = new_tail;
            max = count;
        }
    }
    vector<int> ans;
    ans.push_back(tail);
    ans.push_back(head);
    return ans;
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
    vector<int> ans = sequence(arr, size);
    cout << ans[0] << " " << ans[1];
}