class Solution {
public:
    int k;
    int dp[100005][27];
    int recurr(int idx , string& s , int pre)
    {
        if(idx <0) return 0;
        if(dp[idx][pre - 'a'+1] != -1) return dp[idx][pre - 'a' + 1];
        dp[idx][pre - 'a' + 1] = 0;
        dp[idx][pre - 'a' + 1] = recurr(idx-1,s,pre);
        
        if(pre == 'a'-1)
        dp[idx][pre - 'a' + 1] = max(dp[idx][pre - 'a' + 1], recurr(idx-1,s,s[idx]) + 1);    
        
        else if( pre!= 'a'-1 &&  abs(s[idx]-pre)<=k )
        dp[idx][pre - 'a' + 1] = max(dp[idx][pre - 'a' + 1], recurr(idx-1,s,s[idx]) + 1);
        
        return dp[idx][pre - 'a' + 1];
    }
    int longestIdealString(string s, int k) {
        this->k = k;
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return recurr(n-1,s,'a'-1);
    }
};