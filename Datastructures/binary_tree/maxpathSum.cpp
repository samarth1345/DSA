#include <iostream>
#include "tree.h"
using namespace std;
int solve(treeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;
    int leftsum, rightsum;
    leftsum = max(0, solve(root->left, maxi));
    rightsum = max(0, solve(root->right, maxi));
    //this is taking care of best path from best left path to best right path
    //need for this: if i just return letfsum+rightsum+rootval, we may miss 
    //some path having greater sum in child nodes
    maxi = max(maxi, (leftsum + rightsum + root->data));
    //this is just returning the best path sum from either side and not the
    //cumulative
    return root->data + max(leftsum, rightsum);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    root->printTree();
    int maxi=INT_MIN;
    cout<<max(solve(root,maxi),maxi);
}