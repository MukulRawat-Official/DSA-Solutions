class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount+1][coins.size()+1];
        for(int i = 0;i<=n;i++){dp[0][i] = 1;}
        for(int j = 1;j<=amount;j++) dp[j][0] = 0;
        for(int i = 1;i<=amount;i++){
           for(int j = 1;j<=n;j++) // idx;
           {
                int idx = j - 1;
                dp[i][j] = dp[i][j-1];
                if(coins[idx]<= i) dp[i][j] += dp[i-coins[idx]][j]; 
           }
        }
        
        return dp[amount][n];
    }
};