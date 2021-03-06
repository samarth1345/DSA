//naive solution 
//taking levels as height
#include<iostream>
#include"tree.h"
using namespace std;
int height(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    //returning maximum height of left and right
    return max(height(root->left),height(root->right))+1;
}
int diameter(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int dia=height(root->left)+height(root->right)+1;
    int dialeft=diameter(root->left);
    int diaright=diameter(root->right);
    return max(max(dialeft,diaright),dia);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    root->printTree();
    cout<<diameter(root);
}