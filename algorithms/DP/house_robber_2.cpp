//the only differnce from house_robber1 is we can't include 1st and last element simulataneously so
//we make two differnet arrays one having 1 element and not the last and vice versa for others
int help(vector<int>& arr,int n){
	    int prev=0,prev_prev=0,curr=arr[0];
	    for(int i=1;i<=n;i++){
            curr=max(prev,arr[i-1]+prev_prev);
            prev_prev=prev;
            prev=curr;
	    }
	    return curr;
	}
    int rob(vector<int>& nums) {
        vector<int> t1,t2;
        int n=nums.size();
        t1.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            t1.push_back(nums[i]);
            t2.push_back(nums[i]);
        }
        t2.push_back(nums[n-1]);
        return max(help(t1,n-1),help(t2,n-1));
    }
