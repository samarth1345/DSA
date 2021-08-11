#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
int main()
{
    Node node;
    node.push(10);
    node.push(20);
    node.push(30);
    node.push(40);
    node.print();
    node.Reverse_iter();
    node.print();
}
