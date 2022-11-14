#include<bits/stdc++.h>
using namespace std;
//pass in adjacency matrix where each entry shows if there is direct
//path from some vertice to another vertice then this matrix stores
//edge weight rest all the entries are INT_MAX
//it will make changes at the place itself
//floyd_warshall gives shortest path from each node to all  the nodes
//in the graph
void floyd_warshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    //we try to go from one node to another node by trying intermediary node
    //as all the nodes
    //it is based on dp appproach i.there must be some node which would have 
    //taken the path to desired node which gives us shortest path 
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX)
                    matrix[i][j] = min(matrix[i][via] + matrix[via][j], matrix[i][j]);
            }
        }
    }
}