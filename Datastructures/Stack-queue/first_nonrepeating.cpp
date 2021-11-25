//Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
//B is formed such that we have to find first non-repeating character each time a character
//is inserted to the stream and append it at the end to B. If no non-repeating character is
//found then append '#' at the end of B.
#include <bits/stdc++.h>
using namespace std;
string solve(string A)
{
    unordered_map<char, int> map;
    queue<char> queue;
    queue.push(A[0]);
    string ans = "";
    ans += A[0];
    map[A[0]]++;
    for (int i = 1; i < A.length(); i++)
    {
        map[A[i]]++;
        //if char has not repeated till now,we store it in queue
        if (map[A[i]] <= 1)
            queue.push(A[i]);
        //if there is no char which is nin repeating
        if (queue.size() == 0)
            ans += '#';
        //if current char is not equal to first non repeating char we add first non repeating char
        else if (A[i] != queue.front())
            ans += queue.front();
        //if current char is equal to first non repeating char
        //we have find in queue for non repeating char
        else
        {
            while (map[queue.front()] >= 2 && queue.size())
                queue.pop();
            if (queue.size() == 0)
                ans += '#';
            else
                ans += queue.front();
        }
    }
    return ans;
}
int main()
{
    string in;
    cin >> in;
    cout << solve(in);
}
