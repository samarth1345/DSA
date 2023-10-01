#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct BIT{
	//Always use 1-based indexing
	int bit[N];
	void build(vector<int>& arr){
		for(int i=1;i<=arr.size();i++){
			update(i,arr[i-1]);
		}
	}
	void update(int i, int x){
		for(; i < N; i += (i&-i))
			bit[i] += x;
	}
	int sum(int i){
		int ans = 0;
		for(; i > 0; i -= (i&-i))
			ans += bit[i];
		return ans;
	}
};
int main(){
	
}