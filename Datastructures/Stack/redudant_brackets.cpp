#include<iostream>
#include<stack>
using namespace std;
bool check_redudant(string input)
{
    bool flag=false;
    stack<char> Stack;
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='(')
        {
            Stack.push(input[i]);
        }
        else if(input[i]==')' && flag)
        {
            Stack.pop();
            flag=false;
        }
        else if(input[i]=='+'||input[i]=='-' )
        {
            if(Stack.top()=='(')
            {
                flag=true;
            }
        }
    }
    return !Stack.empty();
}
int main()
{
    string input;
    cin>>input;
    cout<<(bool)check_redudant(input);
}