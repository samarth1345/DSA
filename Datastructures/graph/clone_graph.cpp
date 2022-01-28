#include <bits/stdc++.h>
using namespace std;
//at start we are given refrence of some node in graph
//we will start dfs from the given node and maintain a map of new nodes we 
//are going to make in process, and use them when needed.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
void dfs(unordered_map<int, Node *> &map, Node *node, Node *ans)
{
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        if (map[node->neighbors[i]->val] == NULL)
        {
            Node *temp = new Node(node->neighbors[i]->val);
            map[node->neighbors[i]->val] = temp;
            ans->neighbors.push_back(temp);
            dfs(map, node->neighbors[i], temp);
        }
        else
            ans->neighbors.push_back(map[node->neighbors[i]->val]);
    }
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;
    //new refernce node to be returned
    Node *ans = new Node(node->val);
    unordered_map<int, Node *> map;
    map[node->val] = ans;
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        //dfs has not been done on this node
        if (map[node->neighbors[i]->val] == NULL)
        {
            Node *temp = new Node(node->neighbors[i]->val);
            map[node->neighbors[i]->val] = temp;
            ans->neighbors.push_back(temp);
            dfs(map, node->neighbors[i], temp);
        }
        //dfs has been done we will just push the node we made into 
        //neighbors
        else
            ans->neighbors.push_back(map[node->neighbors[i]->val]);
    }
    return ans;
}