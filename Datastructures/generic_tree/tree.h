#include <bits/stdc++.h>
using namespace std;
template <typename T>
//null point exception has not been taken care of
class tree
{
public:
    T data;
    vector<tree *> subnodes;
    tree(T data)
    {
        this->data = data;
    }
    ~tree()
    {
        for (int i = 0; i < subnodes.size(); i++)
        {
            delete subnodes[i];
        }
    }
    tree<int> *insertTree_recursive()
    {
        int data;
        cout << "enter data" << endl;
        cin >> data;
        tree<int> *newnode = new tree<int>(data);
        int subnodes;
        cout << "Enter no. of subnodes for " << data << endl;
        cin >> subnodes;
        for (int i = 0; i < subnodes; i++)
        {
            tree<int> *childnode = insertTree_recursive();
            newnode->subnodes.push_back(childnode);
        }
        return newnode;
    }
    //using queue
    void insertTree(tree<int> *root)
    {
        queue<tree<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            tree<int> *node = q.front();
            q.pop();
            int subnodes;
            cout << "Enter no. of subnodes for " << node->data << endl;
            cin >> subnodes;
            for (int i = 0; i < subnodes; i++)
            {
                int data;
                cout << "Enter data for subnode " << i + 1 << " of " << node->data << endl;
                cin >> data;
                tree<int> *newnode = new tree<int>(data);
                node->subnodes.push_back(newnode);
                q.push(newnode);
            }
        }
    }
    void printTree_recursive(tree<int> *obj)
    {
        if (obj == NULL) //Not the base case just edge case
        {
            return;
        }
        //No base case because statements are itself acting as base case
        cout << obj->data << "->";
        for (int i = 0; i < obj->subnodes.size(); i++)
        {
            cout << obj->subnodes[i]->data << ",";
        }
        cout << endl;
        for (int i = 0; i < obj->subnodes.size(); i++)
        {
            printTree_recursive(obj->subnodes[i]);
        }
    }
    //levelwise printing
    void printTree(tree<int> *obj)
    {
        queue<tree<int> *> q;
        q.push(obj);
        //display subnodes of node and push it into queue
        while (!q.empty())
        {
            tree<int> *node = q.front();
            q.pop();
            int no_of_subnodes = node->subnodes.size();
            cout << endl
                 << node->data << "->";
            for (int i = 0; i < no_of_subnodes; i++)
            {
                cout << node->subnodes[i]->data << ",";
                q.push(node->subnodes[i]);
            }
        }
        cout << endl;
    }
};