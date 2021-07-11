//permutation with space 
#include<bits/stdc++.h>
using namespace std;
void solve(string str,string op,int n)
{
    if(n==0)                                    //base condition: n is chosen for smaller inputs
    {
        cout<<op<<endl;
        return;
    }
    string op1,op2;
    op1=str;                                     //op1 and op2 are strings which would be formed after taking decisions for space
    op2=str.insert(n,"_");
    solve(op1,op2,n-1);                          //making new calls for new strings made i.e op1 and op2  
    solve(op2,op1,n-1);
}
int main()
{
    string str;
    cin>>str;
    solve(str,str,str.length()-1);
}
/**********************************************************************************************************/
//Another method to solve above question
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op,char ex)
{
    if(ip.length()==0)               //base case
    {
        cout<<ex+op<<endl;           //first char of str(from main) being added before display
        return;
    }
    string op1,op2;
    op1=op+ip[0];
    op2=op+"_"+ip[0];
    ip.erase(0,1);
    solve(ip,op1,ex);
    solve(ip,op2,ex);
}
int main()
{
    string str;
    cin>>str;
    char ex=str[0];            //this is char used to cover first case of string as spaces are allowed only inside string
    str.erase(0,1);
    solve(str,"",ex);
}