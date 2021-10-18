//naive solution for finding if tree is balanced or not
#include<iostream>
#include"tree.h"
using namespace std;
int height(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maxi=1,temp;
    //height of left node
    maxi+=height(root->left);

    //height of right node
    temp=1;
    temp+=height(root->right);
    
    //returning maximum height of left and right
    maxi=max(temp,maxi);
    return maxi;
}
bool isbalanced(treeNode<int> *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(abs(height(root->left)-height(root->right))<=1)
    {
        return isbalanced(root->left)&isbalanced(root->right);
    }
    return false;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(5);
    root->insert();
    root->printTree();
    if(isbalanced(root))
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"not balanced"<<endl;
    }
}