#include <iostream>
#include <vector>
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
        cout<<endl;
    }
    //count no. of nodes
    int countnodes(tree<int> *obj)
    {
        int count = 1;
        for (int i = 0; i < obj->subnodes.size(); i++)
        {
            count += countnodes(obj->subnodes[i]);
        }
        return count;
    }
    int sumofnodes(tree<int> *obj)
    {
        int sum = obj->data;
        for (int i = 0; i < obj->subnodes.size(); i++)
        {
            sum += sumofnodes(obj->subnodes[i]);
        }
        return sum;
    }
    int maxnode(tree<int> *obj)
    {
        int ans = obj->data;
        for (int i = 0; i < obj->subnodes.size(); i++)
        {
            int temp = maxnode(obj->subnodes[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
    int height(tree<int> *obj)
    {
        int ans=1;
        for(int i=0;i<obj->subnodes.size();i++)
        {
            int temp=1;
            temp+=height(obj->subnodes[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
    void printAtdepth(tree<int> *obj,int d)
    {
        if(d==0)
        {
            cout<<obj->data<<" ";
            return;
        }
        for(int i=0;i<obj->subnodes.size();i++)
        {
            printAtdepth(obj->subnodes[i],d-1);
        }
    }
    int leafnodes(tree<int> *obj)
    {
        if(obj->subnodes.size()==0)
        {
            return 1;
        }
        int ans=0;
        for(int i=0;i<obj->subnodes.size();i++)
        {
            ans+=leafnodes(obj->subnodes[i]);
        }
        return ans;
    }
};