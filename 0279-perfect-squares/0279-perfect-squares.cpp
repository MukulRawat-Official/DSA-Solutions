class Solution {
public:
    int dp[(int)1e4+ 1];
    int recurr(int curr){
        if(!curr) return 0;
        if(dp[curr] != -1) return dp[curr];
        int ans = 1e5;
        
        for(int i = 1;i * i <= curr;i++){
            ans = min(ans, recurr(curr - i * i) + 1);
        }
        
        return dp[curr] = ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return recurr(n);
    }
};