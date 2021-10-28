#include <iostream>
#include <unordered_map>
using namespace std;
string pair_with_diff(int *arr, int size, int k)
{
    unordered_map<int, int> map;
    string ans = "No";
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]=i;
    }
    for (int i = 0; i < size; i++)
    {
        if(map[arr[i]-k]!=i)
        {
            ans="yes";
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