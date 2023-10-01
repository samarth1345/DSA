#include<bits/stdc++.h>
using namespace std;
//Time complexity:O(N)
//Space Complexity:O(N)
//z[i]->longest prefix starting at i which is also prefix of string
//note: this can be overlapping
//note: this is 0-based indexed
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
int main(){
	string s;
	cin>>s;
	vector<int> z=z_function(s);
	for(int i:z)
		cout<<i<<" ";
	cout<<endl;
}