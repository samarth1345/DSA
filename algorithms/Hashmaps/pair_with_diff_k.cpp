#include <iostream>
#include <unordered_map>
using namespace std;
string pair_with_diff(int *arr, int size, int k)
{
    unordered_map<int, int> map;
    string ans = "No";
    for (int i = 0; i < size; i++)
    {
        if (map[arr[i]] > 0)
        {
            map[arr[i]] = map[arr[i]] + 1;
        }
        else
        {
            map[arr[i]] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        int help, help_2;
        help = arr[i] - k;
        help_2 = arr[i] + k;
        if (map[help] > 0 || map[help_2] > 0)
        {
            ans = "Yes";
            break;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int k;
        cin >> k;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cout << pair_with_diff(arr, size, k) << endl;
    }
}