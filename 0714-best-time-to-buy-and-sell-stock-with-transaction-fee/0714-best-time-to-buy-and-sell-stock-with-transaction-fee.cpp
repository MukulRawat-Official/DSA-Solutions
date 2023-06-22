int dp[50000][2];
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        for(int i = 0;i<n;i++) dp[i][0] = dp[i][1] = -1;
        function<int(int,int)> recurr = [&](int i , int t){
          if(i == n) return 0;
          int& ans = dp[i][t];
          if(ans != -1) return ans;
          ans = recurr(i+1,t);
          if(t)    ans = max(ans ,recurr(i+1,!t) + prices[i] - fee);
          else ans = max(ans,  recurr(i+1,!t) - prices[i]);
          return ans;
        };
        
        
        return recurr(0,0);
        
        
    }
};