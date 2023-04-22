class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101][101];
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int n , int idx , int rem , auto&& recurr)->long{
          if(idx == group.size()) return rem < 1;
            
          if(dp[idx][n][rem] != -1) return dp[idx][n][rem];
          
          long ans = recurr(n,idx+1,rem,recurr) % mod;
            
          if(group[idx] <= n){
              ans = ans + (recurr(n - group[idx] , idx+1, max(0,rem - profit[idx]) , recurr) % mod);
          }
            
            return dp[idx][n][rem] = ans % mod;
        };
        
        return recurr(n,0,minProfit,recurr);
    }
};