class Solution {
public:
    long dp[31][31][1001];
    int mod = 1e9 + 7;
    int recurr(int idx , int n , int k ,int t)
    {
        if(!t) {
            if( idx > n) return 1;
            return 0;
        }
        if(idx > n) return 0;
        
        if(dp[idx][k][t] != -1) return dp[idx][k][t];
        dp[idx][k][t] = 0;
        for(int i = 1;i<=min(k,t);i++)
        {
           dp[idx][k][t] += recurr(idx+1,n,k,t-i);
           dp[idx][k][t] %= mod;
        }
        
        return dp[idx][k][t] % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
       memset(dp,-1,sizeof(dp));
       return recurr(1,n,k,target);
       
    }
};