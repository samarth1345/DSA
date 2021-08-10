#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *head = NULL;
    static int size;

public:
    Node()
    {
        next = NULL;
    }
    void push(int num)
    {
        size++;
        Node *obj = new Node();
        obj->data = num;
        if (head == NULL)
        {
            head = obj;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = obj;
        }
    }
    bool empty()
    {
        if (head != NULL)
        {
            return false;
        }
        return true;
    }
    void print()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    int sizeoflist()
    {
        return size;
    }
};
int Node::size = 0;
int main()
{
    Node node;
    node.push(10);
    node.push(20);
    node.push(30);
    node.push(40);
    node.print();
}