#include<iostream>
#include<stack>
using namespace std;
int minimum_brackets(string string)
{
    if(string.length()%2 !=0)
    {
        return -1;
    }
    stack<char> Stack;
    int start=0;
    int end=string.length()-1;
    for(int i=0;i<string.length();i++)
    {
        Stack.push(string[start]);
        start++;

    }
}