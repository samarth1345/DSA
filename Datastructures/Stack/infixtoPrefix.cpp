#include<bits/stdc++.h>
using namespace std;
string infixtopostfix(string input)
{
    stack<char> Stack;
    string ans="";
    for (int i = input.length()-1; i >=0; i--)
    {
        if (input[i]=='*'||input[i] == '/'||input[i] == '+'||input[i] == '-'||input[i]==')')
        {
            Stack.push(input[i]);
        }
        else if(input[i]=='(')
        {
            while(Stack.top()!=')')
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string input;
    cin >> input;
    input = infixtopostfix(input);
    cout << input << endl;
}