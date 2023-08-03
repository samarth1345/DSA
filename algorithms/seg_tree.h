//seg tree with lazy propogation for sum 
struct segment_tree{
    vector<int> st,lazy;
    int size;
    segment_tree(int n){
        this->size=n;
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(vector<int> &arr){
        build(0,0,size-1,arr);
    }
    void build(int node,int l,int r,vector<int>& arr){
        if(l==r){
            st[node]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*node+1,l,mid,arr);
        build(2*node+2,mid+1,r,arr);
        st[node]=st[2*node+1]+st[2*node+2];
    }
    void update(int start,int end,int val){
        update(0,0,size-1,start,end,val);
    }
    void update(int node,int l,int r,int start,int end,int val){
        if(l>end || r<start)
            return;
        if(lazy[node]!=0){
            st[node]+=(lazy[node]*(r-l+1));
            if(l!=r){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(l>=start && r<=end){
            st[node]+=(r-l+1)*val;
            if(l!=r){
                lazy[2*node+1]+=val;
                lazy[2*node+2]+=val;
            }
            return;
        }
        int mid=l+(r-l)/2;
        update(2*node+1,l,mid,start,end,val);
        update(2*node+2,mid+1,r,start,end,val);
        st[node]=st[2*node+1]+st[2*node+2];
    }
    int query(int start,int end){
        return query(0,0,size-1,start,end);
    }
    int query(int node,int l,int r,int start,int end){
        if(end < l || start > r)
            return 0;
        if(lazy[node]!=0){
            st[node]+=(lazy[node]*(r-l+1));
            if(l!=r){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(l>=start && r<=end){
            return st[node];
        }
        int mid=l+(r-l)/2;
        return query(2*node+1,l,mid,start,end)+query(2*node+2,mid+1,r,start,end);
    }
};

//Seg tree for min
struct seg_tree{
    vector<int> st;
    seg_tree(int n){
        st.resize(4*n,INT_MAX);
    }
    void update(int node,int l,int r,int idx,int val){
        if(l==idx && r==idx){
            st[node]=min(st[node],val);
            return;
        }
        if(r<idx || l>idx)
            return;
        int mid=(l+r)>>1;
        update(2*node+1,l,mid,idx,val);
        update(2*node+2,mid+1,r,idx,val);
        st[node]=min(st[2*node+1],st[2*node+2]);
    }
    int query(int node,int l,int r,int start,int end){
        if(l>=start && r<=end)
            return st[node];
        if(l>end || r<start)
            return INT_MAX;
        int mid = (l + r) >> 1;
        return min(query(2*node+1,l,mid,start,end),query(2*node+2,mid+1,r,start,end));
    }
};