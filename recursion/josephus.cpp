//josephus problem
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void joseph(int pos,int k,vector<int> army)
{
    if(army.size()==1)                      //base condition
    {
        cout<<army[0]<<endl;
        return;
    }
    int kill_pos=(pos+k)%army.size();      //calculating pos to be killed
    army.erase(army.begin()+kill_pos);     //erasing kill pos
    joseph(kill_pos,k,army);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    vector<int> army;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        army.push_back(i);   
    }
    joseph(0,k-1,army);
    }
    return 0;
}