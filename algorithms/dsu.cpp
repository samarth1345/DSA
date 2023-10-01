#include<bits/stdc++.h>
using namespace std;
struct disjoint_set{
    vector<int> parent,size;
    disjoint_set(int n){
        for(int i=0;i<n;i++) parent.push_back(i),size.push_back(1);
    }  
    void Union(int a,int b){
        int p1=find_parent(a);
        int p2=find_parent(b);
        if(p1==p2)
            return;
        if(size[p1]>size[p2]){
            size[p1]+=size[p2];
            parent[p2]=p1;
        }else{
            size[p2]+=size[p1];
            parent[p1]=p2;
        }
    }
    int find_parent(int a){
        if(a==parent[a])
            return a;
        return parent[a]=find_parent(parent[a]);
    }
};