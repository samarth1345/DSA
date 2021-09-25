#include <iostream>
#include <stack>
using namespace std;
//keep on building stack till ) comes
//when ) comes start poping out elements
//with conditions
bool check_redudant(string input)
{
    stack<char> Stack;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            Stack.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (Stack.top() == '(')
            {
                return true;
            }
            while (Stack.size() > 0 && Stack.top() != '(')
            {
                Stack.pop();
            }
            if (Stack.size() > 0)
            {
                Stack.pop();
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;
        if (check_redudant(input))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}