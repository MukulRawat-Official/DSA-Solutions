class Solution {
public:
    int dp[5001][301];
    int recurr(vector<int>&coins, int amount , int idx){
        if(amount<0) return 0;
        if(!amount) return 1;
        if(idx == coins.size()) return 0;
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int ans = recurr(coins,amount,idx+1);
        
        ans += recurr(coins,amount - coins[idx] ,idx);
        
        return dp[amount][idx] = ans;
        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int ans = recurr(coins,amount,0);
        // for(int i = 0;i<6;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        return ans;
    }
};