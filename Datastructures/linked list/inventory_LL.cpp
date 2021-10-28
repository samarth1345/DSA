#include <bits/stdc++.h>
using namespace std;
int getinstock(string str)
{
    stringstream convert(str);
    int x = 0;
    convert >> x;
    return x;
}
class sub_sub_category
{
public:
    string category;
    unordered_map<string,bool> sub_sub_map;
    sub_sub_category *next;
    sub_sub_category *head;
    sub_sub_category *tail;
    int instock;
    sub_sub_category()
    {
        next = NULL;
        head = NULL;
        tail = NULL;
    }
    sub_sub_category* command_I(string query,sub_sub_category *tosearch)
    {
        string new_q=query.substr(6,2);
        if(tosearch == NULL)
        {
            
        }
        return head;
    }
};
class sub_category
{
public:
    string category;
    unordered_map<string,bool> sub_map;
    int instock;
    sub_sub_category *sub_sub;
    sub_category *next;
    sub_category *head;
    sub_category *tail;
    sub_category()
    {
        sub_sub = NULL;
        next = NULL;
        head = NULL;
        tail = NULL;
    }
    sub_category* command_I(string query,sub_category* tosearch,int instock)
    {
        string new_q=query.substr(4,2);
        sub_category* new_sub=new sub_category();
        if(tosearch==NULL)
        {
            new_sub->category=new_q;
            new_sub->instock=instock;
            sub_sub_category *new_sub_sub=new sub_sub_category();
            new_sub->sub_sub=new_sub_sub->command_I(query,NULL);
        }
        if(head==NULL)
        {
            head=new_sub;
            tail=new_sub;
        }
        else
        {
            tail->next=new_sub;
        }
        sub_map[new_q]=true;
        return head;
    }
};
class main_category
{
public:
    string category;
    unordered_map<string,bool> main_map;
    int instock;
    sub_category *sub;
    main_category *next;
    main_category *head;
    main_category *tail;
    main_category()
    {
        sub = NULL;
        next = NULL;
        head = NULL;
        tail = NULL;
    }
    void command_I(string query)
    {
        string new_q=query.substr(2,2);
        int instock=getinstock(query.substr(9,query.length()-9));
        main_category *new_node=new main_category();
        if(!main_map[new_q])
        {
            new_node->category=new_q;
            new_node->instock=instock;
            sub_category* new_sub=new sub_category();
            new_node->sub=new_sub->command_I(query,NULL,instock);
        }
        if(head==NULL)
        {
            head=new_node;
            tail=new_node;
        }
        else
        {
            tail->next=new_node;
        }
        main_map[new_q]=true;
    }
    void command_M(string query)
    {
    }
    void command_S(string query)
    {
    }
    void command_P(string query)
    {
    }
};
int main()
{
    int queries;
    cin >> queries;
    main_category *object = new main_category();
    while (queries--)
    {
        string query;
        cin >> query;
        char key = query[0];
        switch (key)
        {
        case 'I':
            object->command_I(query); break;
        case 'M':
            object->command_I(query); break;
        case 'S':
            object->command_I(query); break;
        case 'P':
            object->command_I(query); break;
        default:
            break;
        }
    }
}