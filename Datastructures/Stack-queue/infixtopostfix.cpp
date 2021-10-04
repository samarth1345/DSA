//use brackets properly
#include<bits/stdc++.h>
using namespace std;
string infixtopostfix(string input)
{
    stack<char> Stack;
    string ans="";
    for (int i = 0; i <input.length(); i++)
    {
        if (input[i]=='*'||input[i] == '/'||input[i] == '+'||input[i] == '-'||input[i]=='(')
        {
            Stack.push(input[i]);
        }
        //if closed bracket comes then 
        //push all elements to string until open bracket comes
        else if(input[i]==')')
        {
            while(Stack.top()!='(')
            {
                ans+=Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
        else
        {
            ans+=input[i];
        }
    }
    return ans;
}
int main()
{
    string input;
    cin >> input;
    input = infixtopostfix(input);
    cout << input << endl;
}