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
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<"height of given tree is "<<height(root);
}