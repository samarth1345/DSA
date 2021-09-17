#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
    //Your code here
    unordered_map<int, int> map;
    vector<int> ans;
    int count = 0;
    //storing frequency of each element of A1
    for (int i = 0; i < N; i++)
    {
        map[A1[i]]++;
    }
    //making new vector 
    for (int i = 0; i < M; i++)
    {
        //if element of A2 is present in A1 pushing it to Ans 
        //no of times it hs occured in A1
        if (map[A2[i]] > 0)
        {
            int size = map[A2[i]];
            while (size--)
            {
                count++;
                ans.push_back(A2[i]);
            }
            map[A2[i]] = 0;
        }
    }
    //merge sort on A1
    sort(A1.begin(), A1.end());
    //pushing leftover elements
    for (int i = 0; i < N; i++)
    {
        if (map[A1[i]] > 0)
        {
            ans.push_back(A1[i]);
        }
    }
    return ans;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> A1,A2;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        A1.push_back(temp);
    }
    for(int i=0;i<M;i++)
    {
        int temp;
        cin>>temp;
        A2.push_back(temp);
    }
    vector<int> Ans=sortA1ByA2(A1,N,A2,M);
    while(Ans.size())
    {
        cout<<Ans.front()<<" ";
        Ans.erase(Ans.begin());
    }
    return 0;
}