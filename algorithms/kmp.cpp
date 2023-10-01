#include<bits/stdc++.h>
using namespace std;

//Time complexity: O(N) Amortized
//Space complexity: O(N)
//lps[i]->longest prefix which is also a suffix till i
//note: this is 1-based indexed
vector<int> getPi(string& s){
    int n=s.length();
    vector<int> lps(n+1);
    int i=0,j=-1;
    lps[0]=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j])
            j=lps[j];
        i++;j++;
        lps[i]=j;
    }
    return lps;
}

/*--------------------------------------------------------------------------------------*/

//APPLICATIONS
//1.
int FindOccurence(string s,string t){
    //s->pattern
    //t->text
    string temp=s+"#"+t;
    vector<int> lps=getPi(temp);
    int count=0;
    for(int i=s.length()+2;i<=temp.length();i++){
        count+=(lps[i]==s.length());
    }
    return count;
}
//2.
int FindSmallesPeriod(string s){
    vector<int> lps=getPi(s);
    int prob_ans=lps.back();
    int n=s.length();
    int period=n-prob_ans;
    if(n%period == 0)
        return period;
    return n;
}
//3.
//can Also find longest prefix which is suffix by doing kmp on rev(s)+"#"+s

int main(){
    string s;
    cin>>s;
    vector<int> lps=getPi(s);
    for(int i:lps)
        cout<<i<<" ";
    cout<<endl;
}