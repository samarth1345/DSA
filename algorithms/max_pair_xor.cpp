class trie{
public:
    trie* bin[2];
    trie(){
        bin[0]=NULL;
        bin[1]=NULL;
    }
    void insert(int idx,int num){
        if(idx==-1)
            return;
        int bit=((num>>idx)&1);
        if(bin[bit]==NULL){
            bin[bit]=new trie();
        }
        bin[bit]->insert(idx-1,num);
    }
    int get_max_xor(int idx,int num){
        if(idx==-1)
            return 0;
        int bit=((num>>idx)&1);
        int ans=0;
        if(bin[!bit]!=NULL){
            ans|=(1<<idx);
            ans|=(bin[!bit]->get_max_xor(idx-1,num));
        }else{
            ans|=(bin[bit]->get_max_xor(idx-1,num));
        }
        return ans;
    }
};
int findMaximumXOR(vector<int>& nums) {
    trie *t=new trie();
    for(int i:nums){
        t->insert(30,i);
    }
    int mx_xor=0;
    for(int i:nums){
        mx_xor=max(mx_xor,t->get_max_xor(30,i));
    }
    return mx_xor;
}