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
            count++;
            int j, k;
            new_head = new_tail =arr[i];
            if (map[arr[i] - 1])
            {
                j = arr[i] - 1;
            }
            if (map[arr[i] + 1])
            {
                k = arr[i] + 1;
            }
            while (map[j])
            {
                new_tail = j;
                count++;
                map[j] = false;
                j--;
            }
            while (map[k])
            {
                new_head = k;
                count++;
                map[k] = false;
                k++;
            }
        }
        if (count >= max)
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