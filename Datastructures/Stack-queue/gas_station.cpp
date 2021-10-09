#include <bits/stdc++.h>
using namespace std;
//logic: to make this circular so that we can come back to station from where 
//started we will push all the elements in queue before hand
//and keep popping and pushing
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    queue<pair<pair<int, int>, int>> Queue;
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        Queue.push({{gas[i], cost[i]}, i});
    }
    bool flag = false;
    int start = -1;
    int count = 0;
    int over = 0;
    while (count < (2 * n))
    {
        if ((over + Queue.front().first.first) >= Queue.front().first.second)
        {
            //if we don't have petrol pump befor
            if (!flag)
            {
                start = Queue.front().second;
                flag = true;
            }
            //if we return back to petrol pump where we started 
            else if (start == Queue.front().second)
            {
                return start;
            }
            //calculatin extra petrol after every petrol pump
            over =((over + Queue.front().first.first) - Queue.front().first.second);
        }
        //if we have started at some petrol pump but went out of fuel
        else if(flag )
        {
            over=0;
            //if we had a round of more than no. of petrol pumps
            if(count>n)
            return -1;
            //else we just break sequnece so that if we find a new valid 
            //petrol pump we can start from there
            else
            flag=false;
        }
        //popping and pushing succesively to have circulat illusion
        pair<pair<int, int>, int> pair = Queue.front();
        Queue.pop();
        Queue.push(pair);
        count++;
    }
    return -1;
}
int main()
{
    vector<int> gas,station;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        gas.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        station.push_back(temp);
    }
    cout<<canCompleteCircuit(gas,station);
}