#include <iostream>
#include <stack>
using namespace std;
bool ispar(string x)
{
    // Your code here
    stack<char> Stack;
    int i = 0;
    while (x[i] != '\0')
    {
        if (x[i] == '[' || x[i] == '(' || x[i] == '{')
        {
            Stack.push(x[i]);
        }
        else
        {
            if (Stack.size() > 0)
            {
                char temp = Stack.top();
                if (x[i] - temp > 2)
                {
                    return false;
                }
                else
                {
                    Stack.pop();
                }
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (!Stack.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string x;
    cin >> x;
    cout << ispar(x);
}