#include<iostream>
#include<vector>
using namespace std;
class stack
{
    int top;
    vector<int> arr;
    public:
    stack()
    {
        top=-1;   
    }
    void push(int num)
    {
        arr.push_back(num);
        top++;
    }
    void pop()
    {
        top--;
    }
    int Top()
    {
        return arr[top];
    }
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    stack obj;
    obj.push(5);
    cout<<obj.Top()<<endl;
    obj.pop();
    if(obj.empty())
    {
        cout<<"Stack empty";
    }
    return 0;
}