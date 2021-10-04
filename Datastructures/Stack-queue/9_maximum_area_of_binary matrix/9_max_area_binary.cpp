#include<iostream>
#include<vector>
#include"MAB.cpp"      //this is another file having code for finding max area of histogram  
using namespace std;
vector<int> MAB(vector<vector<int>> v,int r,int c)
{
    vector<int> ans;
    vector<int> temp(r,0);
    //single row of binary matrix is being sent as vector to "MAB" file which will return max area of histogram
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)             
        {
            if(v[i][j]==0)
            {
                temp[j]=0;               //if there is a 0 in row,continuity for finding max area will be brokem bu putting 0 and disregarding previous histogram 
            }
            else
            {
                temp[j]+=1;             //if there is 1 in row it will add to height of histogram
            }
        }
        int help;
        help=MAH(temp);
        ans.push_back(help);           //max of histogram
    }
    return ans;
}
int main()
{
    vector<vector<int>> v;
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        vector<int> temp;
        for(int j=0;j<c;j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }
    vector<int> ans;
    ans=MAB(v,r,c);
    int maximum;
    for(int i=0;i<ans.size()-1;i++)
    {
        maximum=max(ans[i],ans[i+1]);
    }
    cout<<maximum;
    return 0;
}