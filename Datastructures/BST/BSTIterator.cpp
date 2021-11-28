#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:this could have easily been done if we had used O(N) space but 
//we will use only O(H) space,in constructor we will iterate to leftmost node(push nodes
//in stack) as it is smallest node in BST then as we return next, we will pop
//and also check if it has right node and if there is we will similarily iterate
//to leftmost node of right subtree(This is similar to inorder traversal)
class BSTIterator
{
public:
    stack<TreeNode *> Stack;
    BSTIterator(TreeNode *root)
    {
        help(root);
    }
    void help(TreeNode *root)
    {
        if (root)
        {
            TreeNode *temp = root;
            while (temp)
            {
                Stack.push(temp);
                temp = temp->left;
            }
        }
    }
    int next()
    {
        TreeNode *temp = Stack.top();
        int data = temp->val;
        Stack.pop();
        if (temp->right)
            help(temp->right);
        return data;
    }

    bool hasNext()
    {
        return !Stack.empty();
    }
};
int main()
{
    TreeNode *root=new TreeNode(4);
    root->insert();
    BSTIterator *bst=new BSTIterator(root);
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->hasNext()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
    cout<<bst->next()<<endl;
}