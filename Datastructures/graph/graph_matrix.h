#include <bits/stdc++.h>
using namespace std;
class graph
{
    int no_of_vertices;
    int **Matrix;

public:
    graph(int val)
    {
        no_of_vertices = val;

        int **temp = new int *[no_of_vertices];
        for (int i = 0; i < no_of_vertices; ++i)
            temp[i] = new int[no_of_vertices];

        Matrix=temp;
    }
    void input(int vertice1, int vertice2)
    {
        Matrix[vertice1 - 1][vertice2 - 1] = 1;
        Matrix[vertice2 - 1][vertice1 - 1] = 1;
    }
};