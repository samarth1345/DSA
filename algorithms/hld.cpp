#include "bits/stdc++.h"
using namespace std;
const int mxN = 2e5+5;
vector<int> adj[mxN];
int dp[mxN], depth[mxN], par[mxN];
int heavy[mxN], head[mxN], id[mxN];
int seg[10*mxN];
int N;
int val[mxN];
//dp    -> no of nodes in subtree
//depth -> depth of node
//par   -> parent of each node
//heavy -> heavy child of each node
//head  -> head of each chain
//id    -> index of nodes according to the chains in which they are
//seg   -> segment tree array
//val   -> value of each node in the tree
//adj   -> adjacency list

//update the val of node in a tree
void update(int k, int x) {
    k += N; seg[k] = x; k >>= 1;
    while (k > 0) {
        seg[k] = max(seg[2*k], seg[2*k+1]);
        k >>= 1;
    }
}
//this is used by path for processing path queries
int query(int a, int b) {
    a += N, b += N;
    int s = 0;
    while (a <= b) {
        if (a & 1) {
            s = max(s, seg[a]);
            a++;
        }
        if (~b & 1) {
            s = max(s, seg[b]);
            b--;
        }
        a >>= 1, b >>= 1;
    }
    return s;
}
//this is calculating heavy child,subtree sum and depth of each node
void dfs(int s, int p) {
    dp[s] = 1;
    int mx = 0;
    for (auto i: adj[s]) if (i != p) {
        par[i] = s;
        depth[i] = depth[s] + 1;
        dfs(i, s);
        dp[s] += dp[i];        
        if (dp[i] > mx)
            mx = dp[i], heavy[s] = i;
    }
}
//here we are storing indices for each node according to tha chain it belongs
//also we are marking the head of chain to which each node belongs to
//also we are storing values in seg_tree as we mark indices
int cnt = 0;
void hld(int s, int h) {
    head[s] = h;
    id[s] = ++cnt;
    //putting values in seg_tree
    update(id[s]-1, val[s]);
    if (heavy[s])
        hld(heavy[s], h);
    for (auto i: adj[s]) {
        if (i!=par[s] && i!=heavy[s])
            hld(i, i);
    }
}
//this function returns required value for a path
int path(int x, int y){
    int ans = 0;
    while (head[x] != head[y]) {
        if (depth[head[x]] > depth[head[y]])
            swap(x, y);
        ans = max(ans, query(id[head[y]]-1, id[y]-1));
        y = par[head[y]];
    }
    if(depth[x] > depth[y]) 
        swap(x, y);
    ans = max(ans, query(id[x]-1, id[y]-1));
    return ans;
}

//----------DIRECTIONS OF USE-------------//
//IN THE SAME ORDER
//call dfs(1,0)    -> 1 based indexing
//call hld(1,1)    -> 1 based indexing
//to update a node -> update(id[node]-1,val);
//to query a path  -> path(a,b)