int dp[2001][2001];
    bool help(vector<int>& stones,int j,int prev,int n){
        if(j==n)
            return true;
        if(dp[j][prev]!=-1)
            return dp[j][prev];
        bool ans=false;
        for(int i=prev-1;i<=prev+1;i++){
            int t=j+1;
            while(t<=n && (stones[t]<=stones[j]+i)){
                if(stones[t]==(stones[j]+i))
                {
                    ans=ans|help(stones,t,i,n);
                    break;
                }
                t++;
            }
        }
        return dp[j][prev]=ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        memset(dp,-1,sizeof(dp));
        return help(stones,1,1,stones.size()-1);
    }
