class disjoint_set
{
    int no_of_vertices;
    vector<int> parent, size;

public:
    disjoint_set(int n)
    {
        no_of_vertices = n;
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find_parent(int node)
    {
        int temp = node;
        while (parent[temp] != temp)
        {
            temp = parent[temp];
        }
        if (parent[node] != temp)
            parent[node] = temp;
        return temp;
    }
    void Union(int node1, int node2)
    {
        int parent1, parent2;
        parent1 = find_parent(node1);
        parent2 = find_parent(node2);
        if (size[parent1] >= size[parent2])
        {
            size[parent1]++;
            parent[parent2] = parent1;
        }
        else
        {
            size[parent2]++;
            parent[parent1] = parent2;
        }
    }
};