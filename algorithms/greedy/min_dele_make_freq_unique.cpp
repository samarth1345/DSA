#include <bits/stdc++.h>
using namespace std;
//could have used 26 sized array instead of map
int minDeletions(string s)
{
    unordered_map<char, int> mymap;
    map<int, int, greater<int>> fre;
    int size = s.size();
    for (int i = 0; i < size; i++)
        mymap[s[i]]++;
    for (auto i : mymap)
        fre[i.second]++;
    int count = 0;
    for (auto i : fre)
    {
        if (i.second > 1 && i.first != 0)
        {
            int temp = 1, win = i.second - 1;
            for (int j = 1; j <= win; j++)
            {
                count += temp;
                fre[i.first - temp]++;
                if (i.first > temp)
                    temp++;
            }
        }
    }
    return count;
}