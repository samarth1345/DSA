int dp[101][101][101];
int help(string &text1, string &text2,string &text3, int len1, int len2,int len3)
{
    if (len1 == -1 || len2 == -1 || len3==-1)
        return 0;
    if (dp[len1][len2][len3] != -1)
        return dp[len1][len2][len3];
    if ((text1[len1] == text2[len2]) && (text2[len2] == text3[len3]))
    {
        return dp[len1][len2][len3] = 1 + help(text1, text2, text3, len1 - 1, len2-1,len3-1);
    }
    int mx=-1;
    for(int i=-1;i<=0;i++){
        for(int j=-1;j<=0;j++){
            for(int k=-1;k<=0;k++){
                if(!(i==0 && j==0 && k==0)){
                    mx=max(mx,help(text1,text2,text3,len1+i,len2+j,len3+k));
                }
            }
        }
    }
    return dp[len1][len2][len3]=mx;
}
int LCS(string A, string B, string C, int n, int m, int k)
{
	memset(dp, -1, sizeof(dp));
    return help(A, B, C, n-1, m-1,k-1);
}
