class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[0] = 1;
       
        for(int i = 2;i<=n;i++){
            if(nums[i-1] == nums[i-2])   dp[i] |= dp[i-2];
            if(i == 2) continue;
            if(nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3]) dp[i] |= dp[i-3];
            if(nums[i-3] + 1 ==  nums[i-2] && nums[i-2] + 1 == nums[i-1]) dp[i] |= dp[i-3];
        }
        
        return dp[n];
    }
};