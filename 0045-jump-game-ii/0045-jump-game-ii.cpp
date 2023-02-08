class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        
        for(int i=0;i<n-1;i++)
        {
            int jumps = nums[i];
            
            for(int j =1;j <=jumps && i+j< n; j++)
            {
                dp[i+j] = min(dp[i]+1,dp[i+j]);
            }
            
        }
        
        return dp[n-1];
    }
};