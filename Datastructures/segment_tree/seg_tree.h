#include <bits/stdc++.h>
using namespace std;
struct segment_tree
{
    vector<int> st;
    int n;
    segment_tree() {}
    void init(int n)
    {
        this->n = n;
        st.resize(4 * n); // maximum size of array required to represent segment tree
    }
    void build(vector<int> ip)
    {
        build(ip, 0, n - 1, 0);
    }
    int query(int start, int ending)
    {
        return query(start, ending, 0, n - 1, 0);
    }
    void update(int index, int value)
    {
        update(index, value, 0, n - 1, 0);
    }
    void build(vector<int> ip, int l, int r, int node)
    {
        if (l == r)
        {
            st[node] = ip[l];
            return;
        }
        int mid = (l + r) / 2;
        // building left and right subtree
        build(ip, l, mid, 2 * node + 1);
        build(ip, mid + 1, r, 2 * node + 2);
        // putting value of current node from its children
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
    int query(int start, int ending, int l, int r, int node)
    {
        // no overlap case
        if (r < start || l > ending)
            return 0;
        // full overlap
        if (l >= start && r <= ending)
            return st[node];
        // rest all cases to be handled by recusrion
        int mid = (l + r) / 2;
        return query(start, ending, l, mid, 2 * node + 1) + query(start, ending, mid + 1, r, 2 * node + 2);
    }
    void update(int index, int value, int l, int r, int node)
    {
        if (l == r && l == index)
        {
            st[node] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid)
            update(index, value, l, mid, 2 * node + 1);
        else
            update(index, value, mid + 1, r, 2 * node + 2);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
};