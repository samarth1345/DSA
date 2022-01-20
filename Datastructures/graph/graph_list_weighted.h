#include <bits/stdc++.h>
#define MAX 10
using namespace std;
class graph
{
    int no_of_vertices;
    vector<pair<int,int>> List[MAX];
public:
    graph(int val)
    {
        no_of_vertices = val;
    }
    void input(int vertice1, int vertice2,int weight)
    {
        List[vertice1].push_back({vertice2,weight});
        List[vertice2].push_back({vertice1,weight});
    }
    void input_directed(int vertice1, int vertice2,int weight)
    {
        List[vertice1].push_back({vertice2,weight});
    }
    void print()
    {
        for(int i=1;i<=no_of_vertices;i++)
        {
            cout<<i<<": ";
            for(int j=0;j<List[i].size();j++)
                cout<<"<"<<List[i][j].first<<" "<<List[i][j].second<<">";
            cout<<endl;
        }
    }
    vector<pair<int,int>> *getList()
    {
        return List;
    }
};