#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    deque<int> d;
    int current_gas = 0, i = 0;
    while(1)
    {
        current_gas+=(gas[i%gas.size()]-cost[i%gas.size()]);
        d.push_back(i%gas.size());
        if(current_gas<0)
        {
            while(current_gas<0)
            {
                current_gas-=(gas[d.front()]-cost[d.front()]);
                d.pop_front();
            }
        }
        i++;
        if(d.empty() && i>=gas.size())
        {
            return -1;
        }
        if(!d.empty()&&(d.front() == (i%gas.size())))
        {
            break;
        }
    }
    return d.front();
}
int main()
{
    vector<int> gas, station;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        gas.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        station.push_back(temp);
    }
    cout << canCompleteCircuit(gas, station);
}