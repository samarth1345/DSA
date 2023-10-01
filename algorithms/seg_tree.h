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
//seg tree for sum
struct seg_tree{
    vector<int> st;
    seg_tree(int n){
        st.resize(4*n);
    }
    void update(int node,int l,int r,int idx){
        if(l==idx && r==idx){
            st[node]=1;
            return;
        }
        if(idx>r || idx<l)
            return;
        int mid=(l+r)>>1;
        update(2*node+1,l,mid,idx);
        update(2*node+2,mid+1,r,idx);
        st[node]=st[2*node+1]+st[2*node+2];
    }
    int query(int node,int l,int r,int start,int end){
        if(l>=start && r<=end){
            return st[node];
        }
        if(start>r || end<l)
            return 0;
        int mid=(l+r)>>1;
        return query(2*node+1,l,mid,start,end)+query(2*node+2,mid+1,r,start,end);
    }
};

//seg tree for binary string operations begin toggle on range, find max cons one on range
struct node{
    int max_cons_one,max_cons_zero;
    int left_one,left_zero;
    int right_one,right_zero;
    node(){
        max_cons_zero=0; max_cons_one=0;
        left_zero=0; left_one=0;
        right_zero=0; right_one=0;
    }  
};
struct seg_tree{
    vector<node> st;
    vector<int> lazy;
    seg_tree(int n){
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int node,int l,int r,string &s){
        if(l==r){
            st[node].max_cons_one=(s[l]=='1');
            st[node].max_cons_zero=(s[l]=='0');
            st[node].left_one=(s[l]=='1');
            st[node].left_zero=(s[l]=='0');
            st[node].right_one=(s[l]=='1');
            st[node].right_zero=(s[l]=='0');
            return;
        }
        int mid=l+(r-l)/2;
        build(2*node+1,l,mid,s);
        build(2*node+2,mid+1,r,s);
        st[node].max_cons_one=max({st[2*node+1].max_cons_one,st[2*node+2].max_cons_one,st[2*node+1].right_one+st[2*node+2].left_one});
        st[node].max_cons_zero=max({st[2*node+1].max_cons_zero,st[2*node+2].max_cons_zero,st[2*node+1].right_zero+st[2*node+2].left_zero});
        st[node].left_one=st[2*node+1].left_one;
        if(st[2*node+1].left_one==(mid-l+1)){
            st[node].left_one+=st[2*node+2].left_one;
        }
        st[node].left_zero=st[2*node+1].left_zero;
        if(st[2*node+1].left_zero==(mid-l+1)){
            st[node].left_zero+=st[2*node+2].left_zero;
        }
        st[node].right_one=st[2*node+2].right_one;
        if(st[2*node+2].right_one==(r-(mid+1)+1)){
            st[node].right_one+=st[2*node+1].right_one;
        }
        st[node].right_zero=st[2*node+2].right_zero;
        if(st[2*node+2].right_zero==(r-(mid+1)+1)){
            st[node].right_zero+=st[2*node+1].right_zero;
        }
        // cout<<l<<" "<<r<<" "<<st[node].max_cons_one<<" "<<st[node].max_cons_zero<<" "<<st[node].left_one<<" "<<st[node].left_zero<<" "<<st[node].right_one<<" "<<st[node].right_zero<<endl;
    }
    void flip(int node,int l,int r){
        swap(st[node].max_cons_one,st[node].max_cons_zero);
        swap(st[node].left_one,st[node].left_zero);
        swap(st[node].right_one,st[node].right_zero);
    }
    void update(int node,int l,int r,int start,int end){
        if(lazy[node]!=0){
            flip(node,l,r);
            lazy[node]=0;
            if(l!=r){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
        }
        if(l>=start && r<=end){
            flip(node,l,r);
            if(l!=r){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
            return;
        }
        if(l>end || r<start)
            return;
        int mid=l+(r-l)/2;
        update(2*node+1,l,mid,start,end);
        update(2*node+2,mid+1,r,start,end);
        st[node].max_cons_one=max({st[2*node+1].max_cons_one,st[2*node+2].max_cons_one,st[2*node+1].right_one+st[2*node+2].left_one});
        st[node].max_cons_zero=max({st[2*node+1].max_cons_zero,st[2*node+2].max_cons_zero,st[2*node+1].right_zero+st[2*node+2].left_zero});
        st[node].left_one=st[2*node+1].left_one;
        if(st[2*node+1].left_one==(mid-l+1)){
            st[node].left_one+=st[2*node+2].left_one;
        }
        st[node].left_zero=st[2*node+1].left_zero;
        if(st[2*node+1].left_zero==(mid-l+1)){
            st[node].left_zero+=st[2*node+2].left_zero;
        }
        st[node].right_one=st[2*node+2].right_one;
        if(st[2*node+2].right_one==(r-(mid+1)+1)){
            st[node].right_one+=st[2*node+1].right_one;
        }
        st[node].right_zero=st[2*node+2].right_zero;
        if(st[2*node+2].right_zero==(r-(mid+1)+1)){
            st[node].right_zero+=st[2*node+1].right_zero;
        }
    }
    pair<node,int> query(int Node,int l,int r,int start,int end){
        if(lazy[Node]!=0){
            flip(Node,l,r);
            if(l!=r){
                lazy[2*Node+1]^=1;
                lazy[2*Node+2]^=1;
            }
            lazy[Node]=0;
        }
        if(l>=start && r<=end){
            return {st[Node],r-l+1};
        }
        if(l>end || r<start)
            return {node(),0};
        int mid=l+(r-l)/2;
        auto left1=query(2*Node+1,l,mid,start,end);
        auto right1=query(2*Node+2,mid+1,r,start,end);
        node left=left1.first,right=right1.first;
        node ans;
        ans.max_cons_one=max({left.max_cons_one,right.max_cons_one,left.right_one+right.left_one});
        ans.max_cons_zero=max({left.max_cons_zero,right.max_cons_zero,left.right_zero+right.left_zero});
        ans.left_one=left.left_one;
        if(left.left_one==left1.second){
            ans.left_one+=right.left_one;
        }
        ans.left_zero=left.left_zero;
        if(left.left_zero==left1.second){
            ans.left_zero+=right.left_zero;
        }
        ans.right_one=right.right_one;
        if(right.right_one==right1.second){
            ans.right_one+=left.right_one;
        }
        ans.right_zero=right.right_zero;
        if(right.right_zero==right1.second){
            ans.right_zero+=left.right_zero;
        }
        return {ans,left1.second+right1.second};
    }
};