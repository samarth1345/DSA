#include <bits/stdc++.h>
using namespace std;
//sliding window 
int lengthOfLongestSubstring(string s)
{
    if(s.length()==0)
    return 0;
    unordered_map<char, bool> map;
    int i = 0, j = 0, maxi = 1;
    while (j < s.length())
    {
        //increasing window till repetition
        if (!map[s[j]])
        {
            map[s[j]] = true;
            j++;
        }
        else
        {
            //calculate length of string before repetition
            maxi = max(maxi, (j - i));
            int k=i;
            //shifting first end of window to have no repetitions
            while(s[k]!=s[j])
            {
                map[s[k]]=false;
                k++;
            }
            map[s[k]]=false;
            i=k+1;
        }
    }
    maxi = max(maxi, (j - i));
    return maxi;
}
int main()
{
    string s;
    cin >> s;
    //cout<<lengthOfLongestSubstring(s);
    cout<<INT32_MAX;
}