#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> Stack;
    int size = asteroids.size();
    for (int i = 0; i < size; i++)
    {
        if (Stack.size() == 0 || Stack.top() < 0)
        {
            Stack.push(asteroids[i]);
        }
        else if (Stack.top() > 0)
        {
            if (asteroids[i] > 0)
            {
                Stack.push(asteroids[i]);
            }
            else
            {
                int help = -1 * asteroids[i];
                if (help - Stack.top() >= 0)
                {
                    while (Stack.size() > 0 && (help - Stack.top()) > 0 && Stack.top() > 0)
                    {
                        Stack.pop();
                    }
                    if (Stack.size() == 0 || Stack.top() < 0)
                    {
                        Stack.push(asteroids[i]);
                    }
                    else if (help - Stack.top() == 0)
                    {
                        Stack.pop();
                    }
                }
            }
        }
    }
    vector<int> ans;
    while (Stack.size() > 0)
    {
        ans.push_back(Stack.top());
        Stack.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int size;
    cin >> size;
    vector<int> aster;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        aster.push_back(temp);
    }
    aster = asteroidCollision(aster);
    for (int i = 0; i < aster.size(); i++)
    {
        cout << aster[i] << endl;
    }
}