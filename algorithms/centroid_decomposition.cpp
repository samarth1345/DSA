#include<bits/stdc++.h>
using namespace std;
vector<int> size,mx;
int get_size(int node,int par,vector<int> *list){
	for(int i:list[node]){
		if(i==par)
			continue;
		int temp=get_size(i,node,list);
		size[node]+=temp;
		mx[node]=max(mx[node],temp);
	}
	size[node]++;
	return size[node];
}
int get_centroid(int node,int par,vector<int>* list){
	if(mx[node]<=(mx.size()/2) && (mx.size()-size[node])<=(mx.size()/2))
		return node;
	for(int i:list[node]){
		if(i==par)
			continue;
		int temp=get_centroid(i,node,list);
		if(temp!=-1)
			return temp;
	}
	return -1;
}
vector<int>* decompose(vector<int>* list,int n){
	size.resize(n);
	mx.resize(n);
	get_size(0,-1,list);
	int centroid=get_centroid(0,-1,list);
	
}