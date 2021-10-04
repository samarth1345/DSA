#include <iostream>
#include <stack>
using namespace std;
int minimum_brackets(string str)
{
    //if string is not even in length it can't be balanced
    if (str.length() % 2 != 0)
    {
        return -1;
    }
    
    stack<char> Stack;
    int count = 0;
    //pushing '{' and popping each time '}' occurs
    //also if '}' occurs when stack is empty it has to be
    //reversed and then pushed
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            Stack.push(str[i]);
        }
        else if (str[i] == '}' && Stack.size() > 0)
        {
            Stack.pop();
        }
        else
        {
            count++;
            Stack.push('{');
        }
    }
    //only open brackets are left in stack
    //every two brackets require 1 reversal
    count += (Stack.size() / 2);

    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << minimum_brackets(str) << endl;
    }
}