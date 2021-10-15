#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class treeNode
{
public:
    T data;
    treeNode<T> *left;
    treeNode<T> *right;
    //constructor
    treeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    //insert function
    void insert()
    {
        queue<treeNode<T> *> q;
        q.push(this);
        while (!q.empty())
        {
            treeNode<T> *temp = q.front();
            q.pop();
            T left, right;
            cout << "Enter data for left and right child for " << temp->data << endl;
            cin >> left >> right;
            if (left != -1)
            {
                treeNode<T> *leftchild = new treeNode<T>(left);
                temp->left = leftchild;
                q.push(leftchild);
            }
            if (right != -1)
            {
                treeNode<T> *rightchild = new treeNode<T>(right);
                temp->right = rightchild;
                q.push(rightchild);
            }
        }
    }
    //method to print tree
    void printTree()
    {
        queue<treeNode<T> *> q;
        q.push(this);
        while (!q.empty())
        {
            treeNode<T> *temp = q.front();
            cout<<temp->data<<": ";
            if(temp->left!=NULL)
            {
                cout<<"L"<<temp->left->data<<" ";
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                cout<<"R"<<temp->right->data;
                q.push(temp->right);
            }
            cout<<endl;
            q.pop();
        }
    }
};