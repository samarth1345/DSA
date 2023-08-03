vector<int> solve(vector<int> v)
{
    vector<int> ans;
    stack<pair<int,int>> Stack;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(Stack.size()==0)
        {
            ans.push_back(-1);
        }
        else if(v[i]>Stack.top().first)
        {
            ans.push_back(Stack.top().second);
        }
        else 
        {
            while(Stack.size()!=0 && v[i]<=Stack.top().first)
            {
                Stack.pop();
            }
            if(Stack.size()==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(Stack.top().second);
            }
        }
        Stack.push({v[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
