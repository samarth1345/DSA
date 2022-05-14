vector<int> dijkstras(vector<pair<int,int>> *List, int vertices, int source)
    {
        vector<int> shortest(vertices+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        shortest[source]=0;
        pq.push({0,source});
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            for(auto i:List[p.second])
            {
                if(shortest[i.first]>p.first+i.second)
                {
                    shortest[i.first]=p.first+i.second;
                    pq.push(make_pair(shortest[i.first],i.first));
                }
            }
        }
        return shortest;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> List[n + 1];
        int size = times.size();
        for (int i = 0; i < size; i++)
        {
            List[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> shortest=dijkstras(List,n,k);
        int mx=-1;
        for(int i=1;i<=n;i++)
        {
            if(shortest[i]==INT_MAX)
                return -1;
            mx=max(mx,shortest[i]);
        }
        return mx;
    }
