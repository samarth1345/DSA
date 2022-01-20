#include <bits/stdc++.h>
using namespace std;
class customer
{
public:
    int all, none;
    vector<string> all_list, none_list;
};
bool comp(customer A, customer B)
{
    if (A.none < B.none)
        return true;
    else if (A.none > B.none)
        return false;
    else if (A.all < B.all)
        return true;
    return false;
}
bool check_none(unordered_map<string,bool> map,vector<string> none_list)
{
    int size=none_list.size();
    for(int i=0;i<size;i++)
    {
        if(map[none_list[i]])
        return false;
    }
    return true;
}
void mark_ingredients(unordered_map<string,bool>& map,vector<string> all_list)
{
    int size=all_list.size();
    for(int i=0;i<size;i++)
    {
        map[all_list[i]]=true;
    }
}
void get_max_customer(customer *List, int no_of_customers)
{
    sort(List, List + no_of_customers, comp);
    unordered_map<string,bool> map;
    for(int i=0;i<no_of_customers;i++)
    {
        if(check_none(map,List[i].none_list))
            mark_ingredients(map,List[i].all_list);
    }
    cout<<map.size()<<" ";
    for(auto i:map)
    {
        cout<<i.first<<" ";
    }
}
int main()
{
    int no_of_customer;
    cin >> no_of_customer;
    customer customer_list[no_of_customer];
    for (int i = 0; i < no_of_customer; i++)
    {
        int temp;
        cin >> temp;
        customer_list[i].all = temp;
        for (int j = 0; j < temp; j++)
        {
            string str;
            cin >> str;
            customer_list[i].all_list.push_back(str);
        }
        cin >> temp;
        customer_list[i].none = temp;
        for (int j = 0; j < temp; j++)
        {
            string str;
            cin >> str;
            customer_list[i].none_list.push_back(str);
        }
    }
    get_max_customer(customer_list, no_of_customer);
}