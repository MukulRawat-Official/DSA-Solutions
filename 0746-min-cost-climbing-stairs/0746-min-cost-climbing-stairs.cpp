class Solution {
public:
    int dp[1001] , n;
    int recurr(vector<int>&arr, int i)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        dp[i] = INT_MAX;
        
        for(int  j =1;j<=2;j++)
        {
          dp[i] = min(dp[i] , recurr(arr,i+j) + arr[i]);
        }
        
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(dp,-1,sizeof(dp));
        
        int x = recurr(cost, 0);
        memset(dp,-1,sizeof(dp));
        
        x = min(x , recurr(cost , 1));
        
        return x;
    }
};