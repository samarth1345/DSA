#include<iostream>
#include<stack>
using namespace std;
void reversestring(string line)
{
    stack<string> str;
    for(int i=0;i<line.length();i++)
    {
        string temp="";
        while(line[i]!=' ' && i<line.length())
        {
            temp+=line[i];
            i++;
        }
        str.push(temp);
    }
    while(!str.empty())
    {
        cout<<str.top()<<" ";
        str.pop();
    }
}
int main()
{
    string line;
    getline(cin,line);
    reversestring(line);
}