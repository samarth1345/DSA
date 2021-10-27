#include<bits/stdc++.h>
using namespace std;
string infixtopostfix(string input)
{
    stack<char> Stack;
    string ans="";
    for (int i = input.length()-1; i >=0; i--)
    {
        //same as postfix just starting from behind and treating ")" as "("
        if (input[i]=='*'||input[i] == '/'||input[i] == '+'||input[i] == '-'||input[i]==')')
        {
            Stack.push(input[i]);
        }
        //if open bracket comes then 
        //push all elements to string until closed bracket comes
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
    //reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string input;
    cin >> input;
    input = infixtopostfix(input);
    cout << input << endl;
}