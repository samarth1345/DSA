	int help(int *arr,int n){
	    int prev=0,prev_prev=0,curr;
	    for(int i=1;i<=n;i++){
            curr=max(prev,arr[i-1]+prev_prev);
            prev_prev=prev;
            prev=curr;
	    }
	    return curr;
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    return help(arr,n);
	}
