#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    //constructor
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
    //insert function
    void insert()
    {
        queue<TreeNode*> q;
        q.push(this);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            int left, right;
            cout << "Enter val for left and right child for " << temp->val << endl;
            cin >> left >> right;
            if (left != -1)
            {
                TreeNode *leftchild = new TreeNode(left);
                temp->left = leftchild;
                q.push(leftchild);
            }
            if (right != -1)
            {
                TreeNode *rightchild = new TreeNode(right);
                temp->right = rightchild;
                q.push(rightchild);
            }
        }
    }
    //method to print tree
    void printTree()
    {
        queue<TreeNode *> q;
        q.push(this);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            cout<<temp->val<<": ";
            if(temp->left!=NULL)
            {
                cout<<"L"<<temp->left->val<<" ";
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                cout<<"R"<<temp->right->val;
                q.push(temp->right);
            }
            cout<<endl;
            q.pop();
        }
    }
};