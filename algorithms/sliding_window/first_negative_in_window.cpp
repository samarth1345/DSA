vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<pair<long long, long long>> q;
    int start = 0, end = 0;
    vector<long long> ans;
    if (A[0] < 0)
        q.push({0, A[0]});
    while (end < N)
    {
        while (end < N && end - start + 1 < K)
        {
            end++;
            if (A[end] < 0)
                q.push({end, A[end]});
        }
        while (!q.empty() && q.front().first < start)
            q.pop();
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(q.front().second);
        start++;
        if (end + 1 >= N)
            break;
    }
    return ans;
}