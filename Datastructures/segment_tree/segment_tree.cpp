#include <bits/stdc++.h>
#include "seg_tree.h"
using namespace std;
int main()
{
    vector<int> ip = {1, 2, 3, 4, 5, 6, 7, 8};
    segment_tree *tree = new segment_tree();
    tree->init(ip.size());
    tree->build(ip);
    tree->update(7, 2);
    cout << tree->st[0];
}