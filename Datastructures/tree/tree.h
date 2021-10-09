#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class tree
{
public:
    T data;
    vector<tree *> subnodes;
    tree(T data)
    {
        this->data = data;
    }
};