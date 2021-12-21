#include <bits/stdc++.h>
#define MAX 10
using namespace std;
class graph
{
    int no_of_vertices;
    vector<int> Matrix[MAX];

public:
    graph(int val)
    {
        no_of_vertices = val;
    }
    void input(int vertice1, int vertice2)
    {
        Matrix[vertice1-1].push_back(vertice2);
        Matrix[vertice2-1].push_back(vertice1);
    }
    void print()
    {
        for(int i=0;i<no_of_vertices;i++)
        {
            cout<<i+1<<": ";
            for(int j=0;j<Matrix[i].size();j++)
                cout<<Matrix[i][j]<<" ";
            cout<<endl;
        }
    }
};