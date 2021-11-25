#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(string letters, char target)
{
    int n = letters.length();
    if (target >= letters[n - 1])
        return letters[0];
    int start = 0, end = n - 1, mid;
    char ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (letters[mid] <= target)
            start = mid + 1;
        else
        {
            ans = letters[mid];
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    char target;
    string letters;
    cin>>letters>>target;
    cout<<nextGreatestLetter(letters,target);
}